#include "TextProcessor.h"

std::string TextProcessor::removePunctuation(const std::string& word)
{
    std::string cleanedWord;
    for (char ch : word) {
        if (!ispunct(static_cast<unsigned char>(ch))) {
            cleanedWord += ch;
        }
    }
    return cleanedWord;
}

void TextProcessor::process()
{
    for (const auto& str : stringList) {
        std::istringstream strToStream(str);
        std::string word;

        while (strToStream >> word) {
            word = removePunctuation(word);
            if (!word.empty()) {
                countWords++;
                wordFreq[word]++;
            }
        }
    }
}

std::map<std::string, int> TextProcessor::getFreq() const
{
    return wordFreq;
}

int TextProcessor::getCount()
{
    return countWords;
}