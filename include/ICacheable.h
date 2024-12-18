#ifndef ICACHEABLE_H
#define ICACHEABLE_H

#include <stdexcept>

template<typename Key, typename Value>
class ICacheable {
public:
    virtual ~ICacheable() = default;
    virtual Value get(const Key& key) = 0;
    virtual void put(const Key& key, const Value& value) = 0;
    virtual void clear() = 0;
};

#endif
