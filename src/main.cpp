#include "LRUCache.h"
#include "LFUCache.h"
#include "CacheWrapper.h"
#include "cmdArgumentValidator.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <limits>
#include <string>
#include <stdexcept>

struct FibResult {
    long long value;
    bool fromCache;
};

FibResult fibonacci(int n, CacheWrapper<Key, Value>& cache) {
    if (n == 1) return FibResult{1, false};
    if (n == 2) return FibResult{1, false};

    try {
        std::cout << "Попытка получить Fib(" << n << ") из кэша.\n";
        Value cachedValue = cache.get(n);
        std::cout << "Fib(" << n << ") = " << cachedValue << " (из кэша)\n";
        return FibResult{cachedValue, true};
    } catch (std::runtime_error&) {
        std::cout << "Fib(" << n << ") отсутствует в кеше. Вычисление...\n";
        FibResult fib1 = fibonacci(n - 1, cache);
        FibResult fib2 = fibonacci(n - 2, cache);
        Value result = fib1.value + fib2.value;
        cache.put(n, result);
        std::cout << "Fib(" << n << ") = " << result << " (вычислено и сохранено в кэше)\n";
        return FibResult{result, false};
    }
}

int main(int argc, char* argv[]) {

    std::shared_ptr<ICacheable<int, long long>> cacheImpl;
    int cacheSize = 100;

    try{
        ParsedArgs args = CommandLineValidator::Parse(argc, argv);
        if (args.cacheType == 1){
            cacheImpl = std::make_shared<LRUCache<int, long long>>(cacheSize);
            std::cout << "LRU-кэш\n";
        } else if (args.cacheType == 2){
            cacheImpl = std::make_shared<LFUCache<int, long long>>(cacheSize);
            std::cout << "LFU-кэш\n";
        }
    } catch (WrongArgumentsCountException& e){
        std::cerr << e.what() << '\n';
        return 1;
    } catch (std::invalid_argument& e){
        std::cerr << e.what() << '\n';
        return 1;
    } catch (std::exception &e){
        std::cerr << e.what() << '\n';
        return 1;
    }

    CacheWrapper<int, long long> cache(cacheImpl);

    int n;
    while (true) {
        std::cout << "Введите номер числа Фибоначчи для вычисления (0 для очистки кэша, -1 для выхода): ";
        try {
            if (!(std::cin >> n)) {
                throw std::invalid_argument("Некорректный ввод. Введите число типа int.");
            }

            if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min()) {
                throw std::out_of_range("Введенное число выходит за пределы допустимого диапазона.");
            }

            if (n == -1) {
                break;
            }

            if (n == 0) {
                cache.clear();
                std::cout << "Кэш очищен\n";
                continue;
            }

            if (n < 1) {
                throw std::invalid_argument("Число должно быть положительным.");
            }

            FibResult result = fibonacci(n, cache);
            if (result.fromCache) {
                std::cout << "Fib(" << n << ") = " << result.value << " (in cache)\n";
            } else {
                std::cout << "Fib(" << n << ") = " << result.value << " (computed)\n";
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }
    }

    return 0;
}
