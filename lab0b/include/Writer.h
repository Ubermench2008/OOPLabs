#ifndef WRITER_H
#define WRITER_H
#include "TextProcessor.h"
#include "Reader.h"

class Writer
{
    std::map<std::string, int> wordFreq;
    int countWords; 
public:
    Writer(TextProcessor& processor) : wordFreq(processor.getFreq()), countWords(processor.getCount()) {}
    static bool compareByFrequency(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
    void writeData(const std::string& outputFileName);
    void printTotalWords();
};

#endif