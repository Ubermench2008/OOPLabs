# Устанавливаем компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -I./include -Wall -Wextra -g

# Цели по умолчанию
all: sound_processor

# Компиляция основной программы
sound_processor: src/main.o src/ConfigParser.o src/Converters.o src/Factory.o src/SoundProcessor.o src/WavParser.o src/WavWriter.o
	$(CXX) -finput-charset=UTF-8 -o sound_processor src/main.o src/ConfigParser.o src/Converters.o src/Factory.o src/SoundProcessor.o src/WavParser.o src/WavWriter.o

src/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

src/ConfigParser.o: src/ConfigParser.cpp include/ConfigParser.h
	$(CXX) $(CXXFLAGS) -c src/ConfigParser.cpp -o src/ConfigParser.o

src/Converters.o: src/Converters.cpp include/Converters.h
	$(CXX) $(CXXFLAGS) -c src/Converters.cpp -o src/Converters.o

src/Factory.o: src/Factory.cpp include/Factory.h
	$(CXX) $(CXXFLAGS) -c src/Factory.cpp -o src/Factory.o

src/SoundProcessor.o: src/SoundProcessor.cpp include/SoundProcessor.h
	$(CXX) $(CXXFLAGS) -c src/SoundProcessor.cpp -o src/SoundProcessor.o

src/WavParser.o: src/WavParser.cpp include/WavParser.h
	$(CXX) $(CXXFLAGS) -c src/WavParser.cpp -o src/WavParser.o

src/WavWriter.o: src/WavWriter.cpp include/WavWriter.h
	$(CXX) $(CXXFLAGS) -c src/WavWriter.cpp -o src/WavWriter.o

# Очистка временных файлов
clean:
	rm -f src/*.o sound_processor