CXX = g++
CXXFLAGS = -std=c++17 -I./include -Wall -g

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests

OBJ = $(SRC_DIR)/main.o \
      $(SRC_DIR)/LRUCache.o \
      $(SRC_DIR)/LFUCache.o \
      $(SRC_DIR)/CacheWrapper.o

TEST_OBJ = $(TEST_DIR)/test.o \
           $(SRC_DIR)/LRUCache.o \
           $(SRC_DIR)/LFUCache.o \
           $(SRC_DIR)/CacheWrapper.o

all: main

main: $(OBJ)
	$(CXX) -o main $(OBJ)

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/ICacheable.h $(INCLUDE_DIR)/CacheWrapper.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o

$(SRC_DIR)/LRUCache.o: $(SRC_DIR)/LRUCache.cpp $(INCLUDE_DIR)/LRUCache.h $(INCLUDE_DIR)/ICacheable.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/LRUCache.cpp -o $(SRC_DIR)/LRUCache.o

$(SRC_DIR)/LFUCache.o: $(SRC_DIR)/LFUCache.cpp $(INCLUDE_DIR)/LFUCache.h $(INCLUDE_DIR)/ICacheable.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/LFUCache.cpp -o $(SRC_DIR)/LFUCache.o

$(SRC_DIR)/CacheWrapper.o: $(SRC_DIR)/CacheWrapper.cpp $(INCLUDE_DIR)/CacheWrapper.h $(INCLUDE_DIR)/ICacheable.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/CacheWrapper.cpp -o $(SRC_DIR)/CacheWrapper.o

test: $(TEST_OBJ)
	$(CXX) -o test $(TEST_OBJ)

$(TEST_DIR)/test.o: $(TEST_DIR)/test.cpp \
                     $(INCLUDE_DIR)/ICacheable.h \
                     $(INCLUDE_DIR)/LRUCache.h \
                     $(INCLUDE_DIR)/LFUCache.h \
                     $(INCLUDE_DIR)/CacheWrapper.h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/test.cpp -o $(TEST_DIR)/test.o

.PHONY: all clean test run

run: main
	@echo "Запуск программы с аргументами: $(ARGS)"
	./main $(ARGS)

clean:
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o main test
