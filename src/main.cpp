#include "LRUCache.h"
#include "LFUCache.h"
#include "CacheWrapper.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <limits>

struct FibResult {
    long long value;
    bool fromCache;
};

FibResult fibonacci(int n, CacheWrapper& cache) {
    if (n == 1) return FibResult{0, false};
    if (n == 2) return FibResult{1, false};

    try {
        std::cout << "Попытка получить Fib(" << n << ") из кэша.\n";
        long long cachedValue = cache.get(n);
        std::cout << "Fib(" << n << ") = " << cachedValue << " (из кэша)\n";
        return FibResult{cachedValue, true};
    } catch (std::runtime_error&) {
        std::cout << "Fib(" << n << ") отсутствует в кеше. Вычисление...\n";
        FibResult fib1 = fibonacci(n - 1, cache);
        FibResult fib2 = fibonacci(n - 2, cache);
        long long result = fib1.value + fib2.value;
        cache.put(n, result);
        std::cout << "Fib(" << n << ") = " << result << " (вычислено и сохранено в кэше)\n";
        return FibResult{result, false};
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <тип_кэша>\n";
        std::cerr << "Тип кэша:\n1 - LRU\n2 - LFU\n";
        return 1;
    }

    int cacheType = std::atoi(argv[1]);
    int cacheSize = 100;

    std::shared_ptr<ICacheable> cacheImpl;

    if (cacheType == 1) {
        cacheImpl = std::make_shared<LRUCache>(cacheSize);
        std::cout << "LRU-кэш\n";
    } else if (cacheType == 2) {
        cacheImpl = std::make_shared<LFUCache>(cacheSize);
        std::cout << "LFU-кэш\n";
    } else {
        std::cerr << "Неверный тип кэша. Выберите 1 для LRU или 2 для LFU.\n";
        return 1;
    }

    CacheWrapper cache(cacheImpl);
    int n;

    while (true) {
        std::cout << "Введите номер числа Фибоначчи для вычисления (0 для очистки кэша, -1 для выхода): ";
        if (!(std::cin >> n)) {
            std::cout << "Некорректный ввод. Введите число типа int.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
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
            std::cout << "Введите число типа int\n";
            continue;
        }

        FibResult result = fibonacci(n, cache);
        if (result.fromCache) {
            std::cout << "Fib(" << n << ") = " << result.value << " (in cache)\n";
        } else {
            std::cout << "Fib(" << n << ") = " << result.value << " (computed)\n";
        }
    }

    return 0;
}
