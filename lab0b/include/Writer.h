#ifndef WRITER_H
#define WRITER_H
#include "TextProcessor.h"
#include "Reader.h"

class Writer
{
private:
    int countWords;
    std::string outFileName;
public:
    Writer() = default;
    static bool compareByFrequency(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
    void setFileName(const std::string& str);
    void writeData(std::map<std::string, int>& wordFreq);
    void setCountWords(int count);
    void printTotalWords();
};

#endif