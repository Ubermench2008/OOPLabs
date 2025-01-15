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
    std::cout << "Использование:" << std::endl;
    std::cout << "  sound_processor -h - показать справку" << std::endl;
    std::cout << "  sound_processor -c <config_file> <output_file> <input_file> [additional_files...]" << std::endl;
    std::cout << std::endl;
    std::cout << "Ключи:" << std::endl;
    std::cout << "  -h - Показать справку" << std::endl;
    std::cout << "  -c <config_file> <output_file> <input_file> [additional_files...] - Обработать аудио с конфиг-файлом" << std::endl;
    std::cout << std::endl;
    std::cout << "Конфигурация эффекта в файле <config_file>:" << std::endl;
    std::cout << "  <effect_name> <arguments>" << std::endl;
    std::cout << "Доступные эффекты:" << std::endl;
    std::cout << "  mute <start_time> <end_time> - Отключить звука в интервале" << std::endl;
    std::cout << "  mix $<file_index> <start_time> - Смешивание с дополнительным файлом (индекс начинается с 1)" << std::endl;
    std::cout << "  volume <factor> <start_time> <end_time> - Регулировка громкости" << std::endl;
    std::cout << std::endl;
    std::cout << "Описание эффекта 'volume':" << std::endl;
    std::cout << "  volume <factor> <start_time> <end_time> - Регулирует громкость." << std::endl;
    std::cout << "    <factor> - коэффициент громкости. Значение 1.0 означает исходную громкость, " << std::endl;
    std::cout << "    значения меньше 1.0 уменьшат громкость, а больше 1.0 - увеличат." << std::endl;
    std::cout << "    <start_time> и <end_time> (необязательные) - указывают интервал (в секундах), в " << std::endl;
    std::cout << "    котором будет применяться изменение громкости. Если эти параметры не указаны, " << std::endl;
    std::cout << "    эффект применяется ко всему аудио файлу." << std::endl;
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
