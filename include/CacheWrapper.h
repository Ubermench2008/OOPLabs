#ifndef CACHEWRAPPER_H
#define CACHEWRAPPER_H

#include "ICacheable.h"
#include <memory>
#include <iostream>

class CacheWrapper {
private:
    std::shared_ptr<ICacheable> cache;

public:
    CacheWrapper(std::shared_ptr<ICacheable> c);
    long long get(int key);
    void put(int key, long long value);
    void clear();
};

#endif