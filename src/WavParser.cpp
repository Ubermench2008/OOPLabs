#include <iostream>
#include "WavParser.h"

WavParser::WavParser(std::string fileName): fileName(fileName), header(std::make_shared<Wav_header>()) {}

std::vector<short int> WavParser::parse() {
    std::ifstream file(fileName, std::ios::binary); // читаем файл
    if(!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + fileName);
    }
    
    file.read(reinterpret_cast<char *>(header.get()), sizeof(Wav_header));

    char* junk = new char[header->subchunk2_size + 4];
    file.read(junk, sizeof(char) * (header->subchunk2_size + 4));

    int dataSize;

    file.read(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));
    std::vector<short int> data;
    data.resize(dataSize);
    file.read(reinterpret_cast<char *>(data.data()), dataSize);

    delete[] junk;
    return data;
}

WavParser::~WavParser() {
    free(header);
}
