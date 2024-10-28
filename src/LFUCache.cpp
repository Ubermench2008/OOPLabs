#include "LFUCache.h"

LFUCache::LFUCache(int cap) : capacity(cap), minFreq(0) {}

void LFUCache::updateFreq(std::shared_ptr<CacheNode> node) {
    int freq = node->freq;
    freqMap[freq].remove(node);
    if (freqMap[freq].empty() && freq == minFreq) {
        ++minFreq;
    }
    node->freq++;
    freqMap[node->freq].push_back(node);
}

long long LFUCache::get(int key) {
    auto it = cacheMap.find(key);
    if (it == cacheMap.end()) {
        throw std::runtime_error("Key not found");
    }
    updateFreq(it->second);
    return it->second->value;
}

void LFUCache::put(int key, long long value) {
    if (capacity == 0) return;
    
    auto it = cacheMap.find(key);
    if (it != cacheMap.end()) {
        it->second->value = value;
        updateFreq(it->second);
        return;
    }

    if (cacheMap.size() == capacity) {
        auto node = freqMap[minFreq].front();
        cacheMap.erase(node->key);
        freqMap[minFreq].pop_front();
    }

    auto newNode = std::make_shared<CacheNode>(key, value);
    cacheMap[key] = newNode;
    minFreq = 1;
    freqMap[1].push_back(newNode);
}

long long LFUCache::operator[](int key) {
    return get(key);
}

void LFUCache::clear() {
    cacheMap.clear();
    freqMap.clear();
    minFreq = 0;
}
