#include "singleton-resume-file.hpp"

SingletonResumeFile::SingletonResumeFile(const std::string &file_path)
    : std::ofstream(file_path, std::ios_base::app) {
}

SingletonResumeFile& SingletonResumeFile::getInstance() {
    static SingletonResumeFile me("relatorio.txt");
    return me;
}

SingletonResumeFile::~SingletonResumeFile() {
    close();
}
