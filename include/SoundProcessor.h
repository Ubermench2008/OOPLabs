#include "vector"
#include "string"

class SoundProcessor {
public:
    SoundProcessor(int argc, char** argv);
    void run();
    static std::string input_file_name;
    static std::vector<std::string> other_input_names;
private:
    static void RegisterConverters();
    int argc;
    char** argv;
};
