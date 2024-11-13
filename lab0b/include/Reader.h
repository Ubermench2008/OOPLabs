#ifndef READER_H
#define READER_H
#include "includes.h"

class Reader
{
private:
    std::string filename;
public:
    Reader() = default;

    void setFileName(const std::string& str);

    std::list<std::string> readFile();
};

#endif