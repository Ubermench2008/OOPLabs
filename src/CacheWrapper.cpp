#include "CacheWrapper.h"

CacheWrapper::CacheWrapper(std::shared_ptr<ICacheable> c) : cache(c) {}

long long CacheWrapper::get(int key) {
    return cache->get(key);
}

void CacheWrapper::put(int key, long long value) {
    cache->put(key, value);
}

void CacheWrapper::clear() {
    cache->clear();
}