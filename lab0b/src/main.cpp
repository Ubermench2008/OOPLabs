#include "Reader.h"
#include "TextProcessor.h"
#include "Writer.h"

// int main() {
//     std::locale::global(std::locale("C"));
//     WordFrequencyAnalyzer analyzer;
//     analyzer.readInput("input.txt");     
//     analyzer.processText();               
//     analyzer.writeOutput("out.csv");      
//     analyzer.printTotalWords();
//     return 0;
// }

int main()
{
    std::locale::global(std::locale("C"));

    Reader read("input.txt");
    read.readFile();

    TextProcessor processor(read);
    processor.process();

    Writer write(processor);
    write.writeData("out.csv");

    write.printTotalWords();

    return 0;
}
