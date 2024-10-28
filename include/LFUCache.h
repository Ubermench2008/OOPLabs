#ifndef LFUCACHE_H
#define LFUCACHE_H

#include "ICacheable.h"
#include <unordered_map>
#include <list>
#include <memory>
#include <stdexcept>

class LFUCache : public ICacheable {
private:
    struct CacheNode {
        int key;
        long long value;
        int freq;
        CacheNode(int k, long long v) : key(k), value(v), freq(1) {}
    };

    int capacity;
    int minFreq;
    std::unordered_map<int, std::shared_ptr<CacheNode>> cacheMap;
    std::unordered_map<int, std::list<std::shared_ptr<CacheNode>>> freqMap;

    void updateFreq(std::shared_ptr<CacheNode> node);

public:
    LFUCache(int cap);
    long long get(int key) override;           
    void put(int key, long long value) override; 
    long long operator[](int key); 
    void clear() override; 
};

#endif
