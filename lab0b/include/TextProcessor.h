#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H
#include "Reader.h"

class TextProcessor
{
    std::list<std::string> stringList;        
    std::map<std::string, int> wordFreq;
    int countWords;   
public:
    TextProcessor(Reader& readData) : stringList(readData.getList()), wordFreq(), countWords(0) {}

    std::string removePunctuation(const std::string& word);

    void process();

    std::map<std::string, int> getFreq() const;

    int getCount();
};

#endif