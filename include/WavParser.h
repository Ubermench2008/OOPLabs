#include <string>
#include <vector>
#include <fstream>

#define SAMPLES_IN_SECOND 44100

typedef struct
{
    char chunk_id[4];
    int chunk_size;
    char format[4];
    char subchunk1_id[4];
    int subchunk1_size;
    short int audio_format;
    short int num_channels;
    int sample_rate;			//частота дискретизации (././)
    int byte_rate;
    short int block_align;
    short int bits_per_sample;
    char subchunk2_id[4];
    int subchunk2_size;			//кол-во выборок
} Wav_header;

class WavParser {
public:
    ~WavParser();
    WavParser(std::string fileName);
    std::vector<short int> parse();
    Wav_header* header;
private:
    std::string fileName;
};
