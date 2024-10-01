#include "WordFrequencyAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

WordFrequencyAnalyzer::WordFrequencyAnalyzer() : countWords(0) {}

string WordFrequencyAnalyzer::removePunctuation(const string& word) {
    string cleanedWord;
    for (char ch : word) {
        if (!ispunct(static_cast<unsigned char>(ch))) {
            cleanedWord += ch;
        }
    }
    return cleanedWord;
}

bool WordFrequencyAnalyzer::compareByFrequency(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

void WordFrequencyAnalyzer::readInput(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        exit(1);
    }

    string currentString;
    while (getline(in, currentString)) {
        stringList.push_back(currentString);
    }
    in.close();
}

void WordFrequencyAnalyzer::processText() {
    for (const auto& str : stringList) {
        istringstream strToStream(str);
        string word;

        while (strToStream >> word) {
            word = removePunctuation(word);
            if (!word.empty()) {
                countWords++;
                wordFreq[word]++;
            }
        }
    }
}

void WordFrequencyAnalyzer::writeOutput(const string& filename) {
    ofstream out(filename);

    out.imbue(std::locale("C"));

    if (!out.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        exit(1);
    }

    vector<pair<string, int>> sortedWords(wordFreq.begin(), wordFreq.end());
    sort(sortedWords.begin(), sortedWords.end(), compareByFrequency);

    out << "Word,Frequency,Percentage\n";
    for (const auto& entry : sortedWords) {
        double percentage = (static_cast<double>(entry.second) / countWords) * 100;
        out << entry.first << "," << entry.second << "," << fixed << setprecision(2) << percentage << "%\n";
    }
    out.close();
}

void WordFrequencyAnalyzer::printTotalWords() const {
    cout << "Общее количество слов: " << countWords << endl;
}
