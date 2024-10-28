#ifndef ICACHEABLE_H
#define ICACHEABLE_H

class ICacheable {
public:
    virtual ~ICacheable() = default;
    virtual long long get(int key) = 0;
    virtual void put(int key, long long value) = 0;
    virtual void clear() = 0;
};

#endif