#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H
#include "Reader.h"

class TextProcessor
{
private:
    int countWords{0};   
public:
    TextProcessor() = default;

    std::string removePunctuation(const std::string& word);

    std::map<std::string, int> process(std::list<std::string>& stringList);

    int getCount();
};

#endif