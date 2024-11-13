#include "Writer.h"
bool Writer::compareByFrequency(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
    return a.second > b.second;
}

void Writer::writeData(std::map<std::string, int>& wordFreq)
{
    std::ofstream out(outFileName);
    out.imbue(std::locale("C"));

    if (!out.is_open()) {
        std::cerr << "Ошибка открытия файла: " << outFileName << std::endl;
        exit(1);
    }

    std::vector<std::pair<std::string, int>> sortedWords(wordFreq.begin(), wordFreq.end());
    sort(sortedWords.begin(), sortedWords.end(), compareByFrequency);

    out << "Word,Frequency,Percentage\n";
    for (const auto& entry : sortedWords) {
        double percentage = (static_cast<double>(entry.second) / countWords) * 100;
        out << entry.first << "," << entry.second << "," << std::fixed << std::setprecision(2) << percentage << "%\n";
    }
    out.close();
}

void Writer::setFileName(const std::string& str){
    this->outFileName = str;
}


void Writer::printTotalWords()
{
    std::cout << "Общее количество слов: " << countWords << std::endl;
}

void Writer::setCountWords(int count) {
    this->countWords = count;
}