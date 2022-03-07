#include "graph/graph.hpp"
#include "main-menu/main-menu.hpp"
#include "resume-file/singleton-resume-file.hpp"
#include <ctime>

#define MAX_LEN 80

int main(int argc, char *argv[]){
    Graph g;
    char s[MAX_LEN];
    time_t t = time(0);
    strftime(s, MAX_LEN, "%m/%d/%Y - %r", localtime(&t));
    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file    <<"|-------------------------------------------------------|\n"
            << "|                Relatorio de desempenho                |\n"
            << "|                dos algoritmos de busca                |\n"
            << "|-------------------------------------------------------|\n"
            << "|-------------------------------------------------------|\n"
            << s << "\n\n";
    if (argc == 2) {
        g.read(argv[1]);
    }

    MainMenu m(&g);
    m.menu();
    return 0;
}