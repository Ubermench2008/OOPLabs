#include "Reader.h"

void Reader::readFile() {
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
}

std::list<std::string> Reader::getList() const
{
    return stringList; 
}