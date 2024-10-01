#ifndef WORDFREQUENCYANALYZER_H
#define WORDFREQUENCYANALYZER_H

#include <string>
#include <list>
#include <map>

class WordFrequencyAnalyzer {
protected:  
    std::list<std::string> stringList;        
    std::map<std::string, int> wordFreq;      
    int countWords;                           

    std::string removePunctuation(const std::string& word);

    static bool compareByFrequency(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);

public:
    WordFrequencyAnalyzer();

    void readInput(const std::string& filename);

    void processText();

    void writeOutput(const std::string& filename);

    void printTotalWords() const;

    const std::list<std::string>& getStringList() const { return stringList; }
    const std::map<std::string, int>& getWordFreq() const { return wordFreq; }
    int getCountWords() const { return countWords; }
};

#endif
