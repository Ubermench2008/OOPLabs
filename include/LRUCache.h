#ifndef LRUCACHE_H
#define LRUCACHE_H

#include "ICacheable.h"
#include <list>
#include <unordered_map>
#include <stdexcept>

template<typename Key, typename Value>
class LRUCache : public ICacheable<Key, Value> {
private:
    int capacity;
    std::list<std::pair<Key, Value>> cacheList;
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    Value get(const Key& key) override {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            throw std::runtime_error("Key not found");
        }
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }

    void put(const Key& key, const Value& value) override { 
        if (capacity == 0) return;

        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            it->second->second = value;
            return;
        }

        if ((int)cacheList.size() == capacity) {
            Key lastKey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(lastKey);
        }

        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

    void clear() override {
        cacheList.clear();
        cacheMap.clear();
    }
};

#endif
