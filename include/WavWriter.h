#include <string>
#include <vector>
#include "WavParser.h"

class WavWriter {
public:
    WavWriter(std::string fileName);
    void write(std::vector<short int> data, Wav_header header);
private:
    std::string filename;
};
