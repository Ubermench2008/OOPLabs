TARGET = bin/Analyzer

SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
BIN_DIR = bin
TEST_DIR = tests

SRC_FILES = $(SRC_DIR)/Reader.cpp $(SRC_DIR)/TextProcessor.cpp $(SRC_DIR)/Writer.cpp
TEST_FILES = $(TEST_DIR)/test_main.cpp

CXX = g++
CXXFLAGS = -Wall -I$(INCLUDE_DIR) -I$(LIB_DIR) -std=c++17 -g
LDFLAGS = -lgtest -lpthread

all: $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET): $(BIN_DIR) $(SRC_FILES) $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(SRC_DIR)/main.cpp -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
	rm -f $(BIN_DIR)/test_program
	rm -rf $(BIN_DIR)

run: $(TARGET)
	./$(TARGET)

test: $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) $(SRC_FILES) -o $(BIN_DIR)/test_program $(LDFLAGS)
	./$(BIN_DIR)/test_program
