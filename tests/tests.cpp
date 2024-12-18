#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <stdexcept>

#include "AllFiles.h"

template<typename Key, typename Value>
class MockCache : public ICacheable<Key, Value> {
public:
    MOCK_METHOD(Value, get, (const Key& key), (override));
    MOCK_METHOD(void, put, (const Key& key, const Value& value), (override));
    MOCK_METHOD(void, clear, (), (override));
};

struct FibResult {
    long long value;
    bool fromCache;
};

template<typename Key, typename Value>
FibResult fibonacci(int n, CacheWrapper<Key, Value>& cache) {
    if (n == 1) return {1, false};
    if (n == 2) return {1, false};

    try {
        Value cachedValue = cache.get(n);
        return {cachedValue, true};
    } catch (std::runtime_error&) {
        FibResult fib1 = fibonacci(n - 1, cache);
        FibResult fib2 = fibonacci(n - 2, cache);
        Value result = fib1.value + fib2.value;
        cache.put(n, result);
        return {result, false};
    }
}

using ::testing::_;
using ::testing::Return;
using ::testing::Throw;
using ::testing::Exactly;
using ::testing::NiceMock;
using ::testing::StrictMock;
using ::testing::Return;
using ::testing::Throw;
using ::testing::AnyNumber;

TEST(CmdArgumetsTest, OnceTest) {
    int argc = 5;
    char* argv[argc] = {(char*)"3", (char*)"-1", (char*)"sdfs", (char*)"^$##", (char*)"="};
    char* testedArgv[2] = {};
    for (int i = 0; i < argc; i++){
        testedArgv[1] = argv[i];
        EXPECT_THROW(CommandLineValidator::Parse(2, testedArgv), std::invalid_argument);
    }
    EXPECT_THROW(CommandLineValidator::Parse(3, testedArgv), WrongArgumentsCountException);
}

TEST(LRUCacheTest, BasicOperations) {
    LRUCache<int, long long> lru(2);
    lru.put(1, 10);
    lru.put(2, 20);
    EXPECT_EQ(lru.get(1), 10);
    lru.put(3, 30); 
    EXPECT_THROW(lru.get(2), std::runtime_error); 
    EXPECT_EQ(lru.get(3), 30);
}

TEST(LRUCacheTest, UpdateExistingKey) {
    LRUCache<int, long long> lru(2);
    lru.put(1, 10);
    lru.put(1, 100); 
    EXPECT_EQ(lru.get(1), 100);
}

TEST(LRUCacheTest, ClearCache) {
    LRUCache<int, long long> lru(2);
    lru.put(1, 10);
    lru.put(2, 20);
    lru.clear();
    EXPECT_THROW(lru.get(1), std::runtime_error);
    EXPECT_THROW(lru.get(2), std::runtime_error);
}

TEST(LRUCacheTest, CapacityZero) {
    LRUCache<int, long long> lru(0);
    lru.put(1, 10);
    EXPECT_THROW(lru.get(1), std::runtime_error);
}

TEST(LFUCacheTest, BasicOperations) {
    LFUCache<int, long long> lfu(2);
    lfu.put(1, 10);
    lfu.put(2, 20);
    EXPECT_EQ(lfu.get(1), 10);
    lfu.put(3, 30);
    EXPECT_THROW(lfu.get(2), std::runtime_error);
    EXPECT_EQ(lfu.get(3), 30);
}

TEST(LFUCacheTest, IncreaseFrequency) {
    LFUCache<int, long long> lfu(2);
    lfu.put(1, 10);
    lfu.put(2, 20);
    EXPECT_EQ(lfu.get(1), 10);
    EXPECT_EQ(lfu.get(1), 10); 
    lfu.put(3, 30);
    EXPECT_THROW(lfu.get(2), std::runtime_error);
    EXPECT_EQ(lfu.get(1), 10);
    EXPECT_EQ(lfu.get(3), 30);
}

TEST(LFUCacheTest, ClearCache) {
    LFUCache<int, long long> lfu(2);
    lfu.put(1, 10);
    lfu.put(2, 20);
    lfu.clear();
    EXPECT_THROW(lfu.get(1), std::runtime_error);
    EXPECT_THROW(lfu.get(2), std::runtime_error);
}

TEST(LFUCacheTest, CapacityZero) {
    LFUCache<int, long long> lfu(0);
    lfu.put(1, 10);
    EXPECT_THROW(lfu.get(1), std::runtime_error);
}

TEST(LFUCacheTest, UpdateExistingKey) {
    LFUCache<int, long long> lfu(2);
    lfu.put(1, 10);
    lfu.put(1, 20); 
    EXPECT_EQ(lfu.get(1), 20);
}

TEST(CacheWrapperTest, LRUWrapper) {
    auto lru = std::make_shared<LRUCache<int, long long>>(2);
    CacheWrapper<int, long long> wrapper(lru);
    wrapper.put(1, 10);
    wrapper.put(2, 20);
    EXPECT_EQ(wrapper.get(1), 10);
    wrapper.put(3, 30);
    EXPECT_THROW(wrapper.get(2), std::runtime_error);
    wrapper.clear();
    EXPECT_THROW(wrapper.get(1), std::runtime_error);
}

TEST(CacheWrapperTest, LFUWrapper) {
    auto lfu = std::make_shared<LFUCache<int, long long>>(2);
    CacheWrapper<int, long long> wrapper(lfu);
    wrapper.put(1, 10);
    wrapper.put(2, 20);
    EXPECT_EQ(wrapper.get(1), 10);
    wrapper.put(3, 30);
    EXPECT_THROW(wrapper.get(2), std::runtime_error);
    wrapper.clear();
    EXPECT_THROW(wrapper.get(1), std::runtime_error);
}

TEST(CacheWrapperTest, GetNonExistingKeyThrowsEmptyCacheException) {
    auto lru = std::make_shared<LRUCache<int, long long>>(2);
    CacheWrapper<int, long long> wrapper(lru);
    EXPECT_THROW(wrapper.get(999), EmptyCacheException);
}

TEST(CacheWrapperTest, ClearCache) {
    auto mockCache = std::make_shared<StrictMock<MockCache<int, long long>>>();

    EXPECT_CALL(*mockCache, clear())
        .Times(1);

    CacheWrapper<int, long long> wrapper(mockCache);
    wrapper.clear();
}

TEST(FibonacciTest, ComputeFibWithMocks) {
    auto mockCache = std::make_shared<MockCache<int, long long>>();
    CacheWrapper<int, long long> wrapper(mockCache);

    EXPECT_CALL(*mockCache, get(3))
        .Times(1)
        .WillOnce(Throw(std::runtime_error("Key not found")));

    EXPECT_CALL(*mockCache, put(3, 2))
        .Times(1);

    FibResult res3 = fibonacci(3, wrapper);
    EXPECT_EQ(res3.value, 2);
    EXPECT_FALSE(res3.fromCache);

    EXPECT_CALL(*mockCache, get(3))
        .Times(1)
        .WillOnce(Return(2));

    FibResult res3_cached = fibonacci(3, wrapper);
    EXPECT_EQ(res3_cached.value, 2);
    EXPECT_TRUE(res3_cached.fromCache);
}

TEST(GeneralTest, NonExistentKey) {
    LRUCache<int, long long> lru(2);
    EXPECT_THROW(lru.get(999), std::runtime_error);
}