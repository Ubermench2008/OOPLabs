#include "CustomExceptions.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

struct ParsedArgs {
    int cacheType;
};

class CommandLineValidator {
public:
    static ParsedArgs Parse(int argc, char* argv[]) {
        if (argc != 2) {
            throw WrongArgumentsCountException("Usage: <program> <cache_type>\nValid cache types:\n1 - LRU\n2 - LFU");
        }

        std::string cacheTypeStr = argv[1];
        if (cacheTypeStr != "1" && cacheTypeStr != "2") {
            throw std::invalid_argument("Invalid of cache type. Use 1 - LRU or 2 - LFU");
        }

        int cacheType = std::stoi(cacheTypeStr);
        return ParsedArgs{cacheType};
    }
};