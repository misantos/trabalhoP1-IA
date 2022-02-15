#include "scope-timer.hpp"

using namespace std::chrono;
using namespace std::chrono_literals;

ScopeTimer::ScopeTimer(std::string scope_name, bool in_seconds) :
    scope_name(scope_name),
    print_in_seconds(in_seconds),
    start(high_resolution_clock::now()) {
}

ScopeTimer::~ScopeTimer() {
    const auto elapsed_time = high_resolution_clock::now() - start;

    std::cout << scope_name << " executou por: " ;
    if (print_in_seconds) {
        const duration<double> to_sec = elapsed_time;
        double sec = to_sec.count();
        int min = 0;
        if (sec > 60.0) {
            min = sec / 60;
            sec -= 60.0;
        }
        std::cout << min << " minuto" << (min != 1? "s" : "") <<
        " e " << sec << ' ';
    }else {
        std::cout << elapsed_time.count() << " nano";
    }
    std::cout << ("segundos\n");
    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file << scope_name << " executou por: " << elapsed_time.count() << " nanosegundos\n";
}