#include <iostream>
#include "WavParser.h"

WavParser::WavParser(std::string fileName): fileName(fileName) {}

WavParser::WavParser(std::string fileName): fileName(fileName) {}

std::vector<short int> WavParser::parse() {
    std::ifstream file(fileName, std::ios::binary); // читаем файл
    if(!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + fileName);
    }

    header = new wav_header;

    file.read(reinterpret_cast<char*>(header), sizeof(wav_header));

    char* junk = new char[header->subchunk2_size + 4];
    file.read(junk, sizeof(char) * (header->subchunk2_size + 4));

    int dataSize;

    file.read(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));
    std::vector<short int> data;
    data.resize(dataSize);
    file.read((char *)data.data(), dataSize);

    delete[] junk;
    return data;
}

WavParser::~WavParser() {
    free(header);
}
