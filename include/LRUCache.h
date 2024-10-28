#ifndef LRUCACHE_H
#define LRUCACHE_H

#include "ICacheable.h"
#include <list>
#include <unordered_map>
#include <stdexcept>

class LRUCache : public ICacheable {
private:
    int capacity;
    std::list<std::pair<int, long long>> cacheList;
    std::unordered_map<int, decltype(cacheList.begin())> cacheMap;

public:
    LRUCache(int cap);
    long long get(int key) override;
    void put(int key, long long value) override;
    long long operator[](int key);  
    void clear() override;
};

#endif
