#ifndef SINGLETON
#define SINGLETON

#include <fstream>

class SingletonResumeFile : public std::ofstream {
private:
    //std::ofstream file_buffer;

    SingletonResumeFile(const std::string &file_path);
public:
    static SingletonResumeFile& getInstance();
    ~SingletonResumeFile();
};


#endif