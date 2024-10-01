#include <gtest/gtest.h>
#include "WordFrequencyAnalyzer.h"
#include <fstream>
#include <unistd.h>
#include <vector>
#include <utility>
#include <sstream>
#include <limits.h>
#include <cstdlib>
#include <iostream>

bool compareFreq(std::ifstream& out, const std::vector<std::pair<int, std::string>>& expectedVec) {
    std::string skipLine;
    std::getline(out, skipLine);

    int counter = 0;
    int lineIndex = 2;
    std::string line;
    bool isErrors = false;

    if (expectedVec.empty()) {
        if (std::getline(out, line)) {
            std::cerr << "Ошибка: пустой вектор\n";
            isErrors = true;
        }
        return !isErrors;
    }

    while (std::getline(out, line)) {
        if (counter >= expectedVec.size()) {
            std::cerr << "Ошибка: количество строк больше, чем ожидаемых частот\n";
            isErrors = true;
            break;
        }

        std::istringstream isStr(line);
        std::string word, freqStr, percentStr;

        std::getline(isStr, word, ',');       
        std::getline(isStr, freqStr, ',');   
        std::getline(isStr, percentStr);

        int currFreq = std::stoi(freqStr);

        bool freqM = expectedVec[counter].first != currFreq;
        bool percentM = expectedVec[counter].second != percentStr;

        if (freqM) {
            std::cerr << "Несоответствие частот на строке " << lineIndex << ":\n"
                      << "Строка: " << line << "\n"
                      << "Ожидание: " << expectedVec[counter].first << ", Действительная: " << currFreq << std::endl;
            isErrors = true;
        }

        if (percentM) {
            std::cerr << "Несоответствие процентов на строке " << lineIndex << ":\n"
                      << "Строка: " << line << "\n"
                      << "Ожидание: " << expectedVec[counter].second << ", Действительная: " << percentStr << std::endl;
            isErrors = true;
        }

        counter++;
        lineIndex++;
    }
    return !isErrors;
}

void RunFrequencyTest(const std::string& inputFilePath, const std::string& expectedOutpuFilePath, const std::string& outputFilePath) {

    std::remove(outputFilePath.c_str());

    WordFrequencyAnalyzer analyzer;
    analyzer.readInput(inputFilePath);
    analyzer.processText();
    analyzer.writeOutput(outputFilePath);

    std::ifstream inpcsv(outputFilePath);
    std::ifstream inpexp(expectedOutpuFilePath);

    ASSERT_TRUE(inpcsv.is_open()) << "Не удалось открыть файл: " << outputFilePath;
    ASSERT_TRUE(inpexp.is_open()) << "Не удалось открыть файл: " << expectedOutpuFilePath;

    std::string tempLine;
    std::getline(inpexp, tempLine);
    std::string line;

    std::vector<std::pair<int, std::string>> expectedFreq;
    while (std::getline(inpexp, line)) {
        std::istringstream isStr(line);
        std::string word, freqStr, percentStr;

        std::getline(isStr, word, ',');
        std::getline(isStr, freqStr, ',');
        std::getline(isStr, percentStr);

        int intFreq = std::stoi(freqStr);
        expectedFreq.emplace_back(intFreq, percentStr);
    }

    bool res = compareFreq(inpcsv, expectedFreq);

    ASSERT_TRUE(res) << "Ошибка: частоты или проценты не совпадают с ожидаемыми для файла: " << inputFilePath;

    inpcsv.close();
    inpexp.close();
}

// Тесты
TEST(FrequencyTest1, CheckWordFrequencies1) {
    RunFrequencyTest("../tests/input1.txt", "../build/expectedFiles/expected_output1.csv", "out1.csv");
}

TEST(FrequencyTest2, CheckWordFrequencies2) {
    RunFrequencyTest("../tests/input2.txt", "../build/expectedFiles/expected_output2.csv", "out2.csv");
}

TEST(FrequencyTest3, CheckWordFrequencies3) {
    RunFrequencyTest("../tests/input3.txt", "../build/expectedFiles/expected_output3.csv", "out3.csv");
}

TEST(FrequencyTest4, CheckWordFrequencies4) {
    RunFrequencyTest("../tests/input4.txt", "../build/expectedFiles/expected_output4.csv", "out4.csv");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
