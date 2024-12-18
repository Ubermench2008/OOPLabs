CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Igoogletest/googletest/include -Wall -g -O0 -fprofile-arcs -ftest-coverage -pthread
LDFLAGS = -Lgoogletest/build/lib -lgtest -lgtest_main -lgmock -lgmock_main -pthread -lgcov


SRC_DIR = src
TEST_DIR = tests
INCLUDE_DIR = include

# Если у вас есть main.cpp для запуска, добавьте его сборку:
MAIN_OBJ = $(SRC_DIR)/main.o

TEST_OBJ = $(TEST_DIR)/tests.o

all: tests_run main_run

tests_run: $(TEST_OBJ)
	$(CXX) -o $(TEST_DIR)/tests_run $(TEST_OBJ) $(LDFLAGS)

main_run: $(MAIN_OBJ)
	$(CXX) -o $(SRC_DIR)/main_run $(MAIN_OBJ) $(LDFLAGS)

# Компиляция тестов
$(TEST_DIR)/tests.o: $(TEST_DIR)/tests.cpp \
                     $(INCLUDE_DIR)/ICacheable.h \
                     $(INCLUDE_DIR)/CacheWrapper.h \
                     $(INCLUDE_DIR)/LFUCache.h \
                     $(INCLUDE_DIR)/LRUCache.h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/tests.cpp -o $(TEST_DIR)/tests.o

# Компиляция main (если используете main.cpp)
$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp \
                   $(INCLUDE_DIR)/ICacheable.h \
                   $(INCLUDE_DIR)/CacheWrapper.h \
                   $(INCLUDE_DIR)/LFUCache.h \
                   $(INCLUDE_DIR)/LRUCache.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o

clean:
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*.gcno $(TEST_DIR)/*.o $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcda $(TEST_DIR)/tests_run $(SRC_DIR)/main_run
