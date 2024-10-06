# Название итогового исполняемого файла
TARGET = bin/Analyzer

# Папки с исходниками и заголовками
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
BIN_DIR = bin
TEST_DIR = tests

# Файлы исходников
SRC_FILES = $(SRC_DIR)/Reader.cpp $(SRC_DIR)/TextProcessor.cpp $(SRC_DIR)/Writer.cpp
TEST_FILES = $(TEST_DIR)/test_main.cpp

# Флаги компилятора
CXX = g++
CXXFLAGS = -Wall -I$(INCLUDE_DIR) -I$(LIB_DIR) -std=c++17 -g
LDFLAGS = -lgtest -lpthread

# Цель по умолчанию - сборка проекта
all: $(TARGET)

# Создание bin директории, если она не существует
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Правило для сборки проекта
$(TARGET): $(BIN_DIR) $(SRC_FILES) $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(SRC_DIR)/main.cpp -o $(TARGET) $(LDFLAGS)

# Чистка сборочных файлов
clean:
	rm -f $(TARGET)
	rm -f $(BIN_DIR)/test_program
	rm -rf $(BIN_DIR)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Сборка и запуск тестов
test: $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) $(SRC_FILES) -o $(BIN_DIR)/test_program $(LDFLAGS)
	./$(BIN_DIR)/test_program
