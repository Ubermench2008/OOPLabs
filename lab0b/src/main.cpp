#include "Reader.h"
#include "TextProcessor.h"
#include "Writer.h"

int main()
{
    std::locale::global(std::locale("C"));

    Reader reader;
    reader.setFileName("input.txt");

    auto readerData = reader.readFile();

    TextProcessor processor;

    auto processorData = processor.process(readerData);

    Writer write;
    write.setFileName("out.csv");
    write.setCountWords(processor.getCount());

    write.writeData(processorData);

    write.printTotalWords();

    return 0;
}
