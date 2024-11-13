#include "Reader.h"

std::list<std::string> Reader::readFile() {
    std::list<std::string> stringList;
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        exit(1);
    }

    std::string currentString;
    while (std::getline(in, currentString)) {
        stringList.push_back(currentString);
    }
    in.close();
    return stringList;
}

void Reader::setFileName(const std::string& str){
    this->filename = str;
}