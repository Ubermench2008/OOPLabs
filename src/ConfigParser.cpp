#include "ConfigParser.h"

#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>

ConfigParser::ConfigParser(std::string configName): configName(std::move(configName)) {}

std::vector<ConfigTuple> ConfigParser::Parse() {
    std::ifstream file(configName);
    if(!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + configName);
    }
    std::vector<ConfigTuple> parsed;
    for(std::string line; std::getline(file, line);) {
        std::istringstream s(line);
        std::vector<std::string> args;
        std::string arg;
        while(std::getline(s, arg, ' ')) {
            args.push_back(arg);
        }
        if(args.empty()) {
            throw std::runtime_error("Конфигурационный файл пуст. Usage: sound_processor -h для справки.");
        }
        std::string converterName = args[0];
        ConfigTuple tuple(args[0], args);
        parsed.push_back(tuple);
    }
    return parsed;
};