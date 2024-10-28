#include "LRUCache.h"

LRUCache::LRUCache(int cap) : capacity(cap) {}

long long LRUCache::get(int key) {
    auto it = cacheMap.find(key);
    if (it == cacheMap.end()) {
        throw std::runtime_error("Key not found");
    }
    cacheList.splice(cacheList.begin(), cacheList, it->second);
    return it->second->second;
}

void LRUCache::put(int key, long long value) {
    auto it = cacheMap.find(key);
    if (it != cacheMap.end()) {
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        it->second->second = value;
        return;
    }

    if (cacheList.size() == capacity) {
        int lastKey = cacheList.back().first;
        cacheList.pop_back();
        cacheMap.erase(lastKey);
    }

    cacheList.emplace_front(key, value);
    cacheMap[key] = cacheList.begin();
}

long long LRUCache::operator[](int key) {
    return get(key);
}

void LRUCache::clear() {
    cacheList.clear();
    cacheMap.clear();
}
