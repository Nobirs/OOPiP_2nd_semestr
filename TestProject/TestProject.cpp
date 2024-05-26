#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <random>
#include <tuple>
#include <map>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS

//«Конвертор файлов»

using namespace std;

template<typename T>
class FileConverter {
private:
    T inputFile;
    T outputFile;
    T conversionType;
public:
    FileConverter() : inputFile(T()), outputFile(T()), conversionType(T()) {}
    FileConverter(const T& inputFile, const T& outputFile, const T& conversionType) : inputFile(inputFile), outputFile(outputFile), conversionType(conversionType) {}
    FileConverter(const FileConverter& other) : inputFile(other.inputFile), outputFile(other.outputFile), conversionType(other.conversionType) {}
    ~FileConverter() {}

    T getInputFile() const { return inputFile; }
    T getOutputFile() const { return outputFile; }
    T getConversionType() const { return conversionType; }

    void setInputFile(const T& inputFile) { this->inputFile = inputFile; }
    void setOutputFile(const T& outputFile) { this->outputFile = outputFile; }
    void setConversionType(const T& conversionType) { this->conversionType = conversionType; }

    bool convert() {
        // Implement the PDF conversion logic here
        cout << "Converting " << inputFile << " to " << outputFile << " conversion Type " << conversionType << endl;
        if (rand() % 4 == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class PdfConverter {
private:
    string inputFile;
    string outputFile;
    string pageSize;
    int resolution;
public:
    PdfConverter() : inputFile(""), outputFile(""), pageSize("A4"), resolution(300) {}
    PdfConverter(const string& inputFile, const string& outputFile, const string& pageSize, int resolution) : inputFile(inputFile), outputFile(outputFile), pageSize(pageSize), resolution(resolution) {}
    PdfConverter(const PdfConverter& other) : inputFile(other.inputFile), outputFile(other.outputFile), pageSize(other.pageSize), resolution(other.resolution) {}
    ~PdfConverter() {}

    string getInputFile() const { return inputFile; }
    string getOutputFile() const { return outputFile; }
    string getPageSize() const { return pageSize; }
    int getResolution() const { return resolution; }

    void setInputFile(const string& inputFile) { this->inputFile = inputFile; }
    void setOutputFile(const string& outputFile) { this->outputFile = outputFile; }
    void setPageSize(const string& pageSize) { this->pageSize = pageSize; }
    void setResolution(int resolution) { this->resolution = resolution; }

    bool convert() {
        // Implement the PDF conversion logic here
        cout << "Converting " << inputFile << " to " << outputFile << " with page size " << pageSize << " and resolution " << resolution << " dpi." << endl;
        if (rand() % 2 == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class ImageConverter {
private:
    string inputFile;
    string outputFile;
    string format;
    int quality;
public:
    ImageConverter() : inputFile(""), outputFile(""), format("JPEG"), quality(80) {}
    ImageConverter(const string& inputFile, const string& outputFile, const string& format, int quality) : inputFile(inputFile), outputFile(outputFile), format(format), quality(quality) {}
    ImageConverter(const ImageConverter& other) : inputFile(other.inputFile), outputFile(other.outputFile), format(other.format), quality(other.quality) {}
    ~ImageConverter() {}

    string getInputFile() const { return inputFile; }
    string getOutputFile() const { return outputFile; }
    string getFormat() const { return format; }
    int getQuality() const { return quality; }

    void setInputFile(const string& inputFile) { this->inputFile = inputFile; }
    void setOutputFile(const string& outputFile) { this->outputFile = outputFile; }
    void setFormat(const string& format) { this->format = format; }
    void setQuality(int quality) { this->quality = quality; }

    bool convert() {
        // Implement the image conversion logic here
        cout << "Converting " << inputFile << " to " << outputFile << " in " << format << " format with quality " << quality << "." << endl;
        if (rand() % 2 == 1) return true;
        else return false;
    }
};

class AudioConverter {
private:
    string inputFile;
    string outputFile;
    string format;
    int bitRate;
public:
    AudioConverter() : inputFile(""), outputFile(""), format("MP3"), bitRate(128) {}
    AudioConverter(const string& inputFile, const string& outputFile, const string& format, int bitRate) : inputFile(inputFile), outputFile(outputFile), format(format), bitRate(bitRate) {}
    AudioConverter(const AudioConverter& other) : inputFile(other.inputFile), outputFile(other.outputFile), format(other.format), bitRate(other.bitRate) {}
    ~AudioConverter() {}

    string getInputFile() const { return inputFile; }
    string getOutputFile() const { return outputFile; }
    string getFormat() const { return format; }
    int getBitRate() const { return bitRate; }

    void setInputFile(const string& inputFile) { this->inputFile = inputFile; }
    void setOutputFile(const string& outputFile) { this->outputFile = outputFile; }
    void setFormat(const string& format) { this->format = format; }
    void setBitRate(int bitRate) { this->bitRate = bitRate; }

    bool convert() {
        // Implement the audio conversion logic here
        cout << "Converting " << inputFile << " to " << outputFile << " in " << format << " format with bit rate " << bitRate << " kbps." << endl;
        if (rand() % 2 == 1) return true;
        else return false;
    }
};


class VideoConverter {
private:
    string inputFile;
    string outputFile;
    string format;

    int frameRate;
public:
    VideoConverter() : inputFile(""), outputFile(""), format("MP4"), frameRate(30) {}
    VideoConverter(const string& inputFile, const string& outputFile, const string& format, int width, int height, int frameRate) : inputFile(inputFile), outputFile(outputFile), format(format), frameRate(frameRate) {}
    VideoConverter(const VideoConverter& other) : inputFile(other.inputFile), outputFile(other.outputFile), format(other.format), frameRate(other.frameRate) {}
    ~VideoConverter() {}

    string getInputFile() const { return inputFile; }
    string getOutputFile() const { return outputFile; }
    string getFormat() const { return format; }

    int getFrameRate() const { return frameRate; }

    void setInputFile(const string& inputFile) { this->inputFile = inputFile; }
    void setOutputFile(const string& outputFile) { this->outputFile = outputFile; }
    void setFormat(const string& format) { this->format = format; }
    void setFrameRate(int frameRate) { this->frameRate = frameRate; }

    bool convert() {
        // Implement the video conversion logic here
        cout << "Converting " << inputFile << " to " << outputFile << " in " << format << " and frame rate " << frameRate << " fps." << endl;
        if (rand() % 2 == 1) return true;
        else return false;
    }
}; 


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаем различные объекты конвертеров
    FileConverter<string> textConverter("input.txt", "output.epub", "text to text");
    PdfConverter pdfConverter("input.pdf", "output.pdf", "A4", 300);
    ImageConverter imageConverter("image.jpg", "image.png", "PNG", 90);
    AudioConverter audioConverter("audio.mp3", "audio.wav", "WAV", 192);
    VideoConverter videoConverter("video.mp3", "video.mp4", "MP4", 1920, 1080, 30);

    // Список конвертаций
    vector<tuple<string, string, bool>> conversions = {
        {"user1", "text", textConverter.convert()},
        {"user2", "text", textConverter.convert()},
        {"user1", "pdf", pdfConverter.convert()},
        {"user1", "image", imageConverter.convert()},
        {"user2", "audio", audioConverter.convert()},
        {"user2", "video", videoConverter.convert()},
        {"user1", "pdf", pdfConverter.convert()},
        {"user2", "image", imageConverter.convert()}
    };

    // Группируем результаты по пользователю и формату
    map<string, map<string, vector<bool>>> conversionResults;
    for (const auto& conversion : conversions) {
        string user = get<0>(conversion);
        string format = get<1>(conversion);
        bool success = get<2>(conversion);
        conversionResults[user][format].push_back(success);
    }

    // Выводим информацию о результатах конвертации
    for (const auto& userResults : conversionResults) {
        string user = userResults.first;
        cout << "Результаты конвертации для пользователя " << user << ":" << endl;
        for (const auto& formatResults : userResults.second) {
            string format = formatResults.first;
            cout << "Формат " << format << ":" << endl;
            int successCount = 0, failureCount = 0;
            for (bool success : formatResults.second) {
                if (success) {
                    cout << "  Успешно" << endl;
                    successCount++;
                }
                else {
                    cout << "  Неуспешно" << endl;
                    failureCount++;
                }
            }
            cout << "  Успешных конвертаций: " << successCount << ", неуспешных: " << failureCount << endl;
        }
        cout << endl;
    }

    return 0;
}