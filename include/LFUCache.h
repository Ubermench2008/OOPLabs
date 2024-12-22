#ifndef LFUCACHE_H
#define LFUCACHE_H

#include "ICacheable.h"
#include <unordered_map>
#include <list>
#include <memory>
#include <stdexcept>

template<typename Key, typename Value>
class LFUCache : public ICacheable<Key, Value> {
private:
    struct CacheNode {
        Key key;
        Value value;
        int freq;
        CacheNode(const Key& k, const Value& v) : key(k), value(v), freq(1) {}
    };

    int capacity;
    int minFreq;
    std::unordered_map<Key, std::shared_ptr<CacheNode>> cacheMap;
    std::unordered_map<int, std::list<std::shared_ptr<CacheNode>>> freqMap;

    void updateFreq(std::shared_ptr<CacheNode> node) {
        int freq = node->freq;
        freqMap[freq].remove(node);
        if (freqMap[freq].empty() && freq == minFreq) {
            ++minFreq;
        }
        node->freq++;
        freqMap[node->freq].push_back(node);
    }

public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    Value get(const Key& key) override {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            throw std::runtime_error("Key not found");
        }
        updateFreq(it->second);
        return it->second->value;
    }

    void put(const Key& key, const Value& value) override {
        if (capacity == 0) return;

        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            it->second->value = value;
            updateFreq(it->second);
            return;
        }

        if ((int)cacheMap.size() == capacity) {
            auto node = freqMap[minFreq].front();
            cacheMap.erase(node->key);
            freqMap[minFreq].pop_front();
        }

        auto newNode = std::make_shared<CacheNode>(key, value);
        cacheMap[key] = newNode;
        minFreq = 1;
        freqMap[1].push_back(newNode);
    }

    void clear() override {
        cacheMap.clear();
        freqMap.clear();
        minFreq = 0;
    }
};

#endif
