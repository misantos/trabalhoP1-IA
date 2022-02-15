#include "graph/graph.hpp"
#include "main-menu/main-menu.hpp"
#include "resume-file/singleton-resume-file.hpp"

int main(int argc, char *argv[]){
    Graph g;
    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file    <<"|-------------------------------------------------------|\n"
            << "|                Relatorio de desempenho                |\n"
            << "|                dos algoritmos de busca                |\n"
            << "|-------------------------------------------------------|\n"
            << "|-------------------------------------------------------|\n\n\n";
    if (argc == 2) {
        g.read(argv[1]);
    }

    MainMenu m(&g);
    m.menu();
    return 0;
}