#include <string>
#include "Factory.h"
#include <iostream>
#include <vector>
#include <tuple>
#include "SoundProcessor.h"
#include "ConfigParser.h"
#include "WavWriter.h"

SoundProcessor::SoundProcessor(int argc, char **argv): argc(argc), argv(argv) {}

void PrintHelp() {
    std::ifstream helpFile("help.txt");
    if (!helpFile.is_open()) {
        std::cerr << "Ошибка открытия справочного файла." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(helpFile, line)) {
        std::cout << line << std::endl;
    }
}

void SoundProcessor::RegisterConverters() {
    Factory::RegisterConverter<Converters::MixConverter>("mix");
    Factory::RegisterConverter<Converters::VolumeConverter>("volume");
    Factory::RegisterConverter<Converters::MuteConverter>("mute");
}

void SoundProcessor::run() {
    if (argc < 2) {
        throw std::invalid_argument("Недостаточно аргументов. Использование: sound_processor -h");
    }

    std::string mode(argv[1]);
    if (mode == "-h") {
        PrintHelp();
        return;
    }

    if (mode != "-c") {
        throw std::invalid_argument("Неверный режим. Использование: sound_processor -h для справки.");
    }

    if (argc < 5) {
        throw std::invalid_argument("Недостаточно аргументов для режима -c. Использование: sound_processor -h для справки.");
    }

    RegisterConverters();

    std::string config_file_name = argv[2];
    std::string output_file_name = argv[3];
    input_file_name = argv[4];

    for (int i = 5; i < argc; i++) {
        other_input_names.emplace_back(argv[i]);
    }

    ConfigParser configParser(config_file_name);
    std::vector<ConfigTuple> parsed = configParser.Parse();

    WavParser wavParser(input_file_name);

    std::vector<short int> currentProduct = wavParser.parse();

    for (const ConfigTuple& tuple : parsed) {
        std::string cvtName;
        std::vector<std::string> args;
        std::tie(cvtName, args) = tuple;
        auto converter = Factory::CreateConverter(cvtName, args);
        converter->convert(&currentProduct);
    }
    
    WavWriter wavWriter(output_file_name);
    wavWriter.write(currentProduct, *wavParser.header);
}
