#include <gtest/gtest.h>
#include "Reader.h"
#include "TextProcessor.h"
#include "Writer.h"

TEST(ReaderTest, FileReadSuccess) {
    Reader reader("input.txt");
    reader.readFile();
    auto list = reader.getList();
    EXPECT_GT(list.size(), 0);  // Ожидаем, что файл не пуст
}

TEST(ReaderTest, FileReadEmpty) {
    // Создаем пустой файл
    std::ofstream outFile("tests/empty.txt");
    outFile.close();

    Reader reader("tests/empty.txt");  // Пустой файл
    reader.readFile();
    auto list = reader.getList();
    EXPECT_EQ(list.size(), 0);  // Ожидаем пустой список
}

TEST(ReaderTest, FileNotFound) {
    Reader reader("abracadabra.txt");
    EXPECT_EXIT(reader.readFile(), ::testing::ExitedWithCode(1), "Ошибка открытия файла");
}

TEST(TextProcessorTest, RemovePunctuation) {
    Reader read("input.txt");
    TextProcessor processor(read);

    std::vector<std::string> wordsWithPunctuation = {
        "hello!!!", "world??", "this,is", "a:test", "check;",
        "quotes\"word\"", "parens(word)", "brackets[word]", "curly{word}", "ellipsis..."
    };
    std::vector<std::string> expectedResults = {
        "hello", "world", "thisis", "atest", "check",
        "quotesword", "parensword", "bracketsword", "curlyword", "ellipsis"
    };

    for (size_t i = 0; i < wordsWithPunctuation.size(); ++i) {
        std::string result = processor.removePunctuation(wordsWithPunctuation[i]);
        EXPECT_EQ(result, expectedResults[i]);
    }
}

TEST(TextProcessorTest, CountWords) {
    Reader reader("tests/Loooong.txt");  // Файл должен содержать несколько слов
    reader.readFile();
    TextProcessor processor(reader);
    processor.process();
    EXPECT_EQ(processor.getCount(), 238527);  // Например, файл содержит 5 слов
}

TEST(IntegrationTest, FullWorkflow) {
    // Чтение файла
    Reader reader("tests/test_input.txt");  // Файл с несколькими словами
    reader.readFile();
    ASSERT_GT(reader.getList().size(), 0);  // Убедитесь, что файл не пуст

    // Обработка текста
    TextProcessor processor(reader);
    processor.process();
    EXPECT_GT(processor.getCount(), 0);  // Проверка, что слова были обработаны

    // Запись данных
    Writer writer(processor);
    writer.writeData("tests/integration_output.csv");

    // Проверка содержимого выходного файла
    std::ifstream csvFile("tests/integration_output.csv");
    ASSERT_TRUE(csvFile.is_open());

    std::ifstream expectedFile("tests/expected.csv");
    ASSERT_TRUE(expectedFile.is_open());

    std::string outputLine;
    std::string expectedLine;
    while (std::getline(expectedFile, expectedLine)) {
        ASSERT_TRUE(std::getline(csvFile, outputLine));
        expectedLine.erase(std::remove(expectedLine.begin(), expectedLine.end(), '\r'), expectedLine.end());
        expectedLine.erase(std::remove(expectedLine.begin(), expectedLine.end(), '\n'), expectedLine.end());
        outputLine.erase(std::remove(outputLine.begin(), outputLine.end(), '\r'), outputLine.end());
        outputLine.erase(std::remove(outputLine.begin(), outputLine.end(), '\n'), outputLine.end());
        EXPECT_EQ(outputLine, expectedLine);  // Проверка на полное соответствие строк
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}