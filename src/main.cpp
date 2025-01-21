#include <iostream>
#include "SoundProcessor.h"

int main(int argc, char** argv) {
    try {
        std::setlocale(LC_ALL, "ru_RU.UTF-8");

        SoundProcessor processor(argc, argv);
        processor.run();
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}