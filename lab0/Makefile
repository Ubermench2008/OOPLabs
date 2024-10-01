# Компилятор
CXX = g++

# Флаги компилятора
CXXFLAGS = -c

# Исходные и объектные файлы
SOURCES = main.cpp module1.cpp module2.cpp module3.cpp
OBJECTS = main.o module1.o module2.o module3.o

# Имя выходного исполняемого файла
TARGET = output_program

# Правило для сборки исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Правила для создания объектных файлов
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.o

module1.o: module1.cpp module1.h
	$(CXX) $(CXXFLAGS) module1.cpp -o module1.o

module2.o: module2.cpp module2.h
	$(CXX) $(CXXFLAGS) module2.cpp -o module2.o

module3.o: module3.cpp module3.h
	$(CXX) $(CXXFLAGS) module3.cpp -o module3.o
	
# Правило для очистки объектных и исполняемых файлов
clean:
	rm -f $(OBJECTS) $(TARGET)
