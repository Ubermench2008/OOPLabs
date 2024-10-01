#include "WordFrequencyAnalyzer.h"
#include <iostream>
#include <fstream>
#include <string> 

int main() {
    std::locale::global(std::locale("C"));
    WordFrequencyAnalyzer analyzer;
    analyzer.readInput("input.txt");     
    analyzer.processText();               
    analyzer.writeOutput("out.csv");      
    analyzer.printTotalWords();
    return 0;
}
