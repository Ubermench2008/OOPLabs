#ifndef CACHEWRAPPER_H
#define CACHEWRAPPER_H

#include "ICacheable.h"
#include "CustomExceptions.h"
#include <memory>
#include <iostream>

template<typename Key, typename Value>
class CacheWrapper {
private:
    std::shared_ptr<ICacheable<Key, Value>> cache;

public:
    CacheWrapper(std::shared_ptr<ICacheable<Key, Value>> c) : cache(c) {}

    Value get(const Key& key) {
        try {
            return cache->get(key);
        } catch (std::runtime_error&) {
            throw EmptyCacheException("Key not found in cache");
        }
    }

    void put(const Key& key, const Value& value) {
        cache->put(key, value);
    }

    void clear() {
        cache->clear();
    }
};

#endif
