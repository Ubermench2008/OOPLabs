cmake_minimum_required(VERSION 3.10)
project(WordFrequencyAnalyzerProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Добавляем директорию для заголовочных файлов
include_directories(${PROJECT_SOURCE_DIR}/include)

# Добавляем объектные файлы для основного исполняемого файла
add_library(WordFrequencyAnalyzerLib
    src/WordFrequencyAnalyzer.cpp
)

# Основной исполняемый файл
add_executable(WordFrequencyAnalyzerExecutable
    src/main.cpp
)

# Линкуем библиотеку к основному исполняемому файлу
target_link_libraries(WordFrequencyAnalyzerExecutable WordFrequencyAnalyzerLib)

# Настройка Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавляем тесты
add_executable(WordFrequencyAnalyzerTests
    tests/test_main.cpp
)

# Линкуем библиотеку к тестам (добавляем GTest::Main)
target_link_libraries(WordFrequencyAnalyzerTests
    WordFrequencyAnalyzerLib
    GTest::GTest
    GTest::Main  # Важная часть: добавляем GTest::Main для линковки main() из Google Test
    pthread
)

# Добавляем тесты для запуска
enable_testing()
add_test(NAME WordFrequencyAnalyzerTests COMMAND WordFrequencyAnalyzerTests)
