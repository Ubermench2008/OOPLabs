#ifndef READER_H
#define READER_H
#include "includes.h"

class Reader
{
    std::list<std::string> stringList;
    const std::string filename;
public:
    Reader(const std::string& fileName) : filename(fileName) {}
    Reader() : filename("input.txt") {}

    void readFile();

    std::list<std::string> getList() const;
};

#endif