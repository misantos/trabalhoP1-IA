#include "graph/graph.hpp"
#include "main-menu/main-menu.hpp"
#include "resume-file/singleton-resume-file.hpp"

int main(int argc, char *argv[]){
    Graph g;
    //SingletonResumeFile &file = SingletonResumeFile::getInstance();
    //file << "Ola mundo" << std::endl;
    if (argc == 2) {
        std::cout << "entrando na funcao\n";
        g.read(argv[1]);
    }

    MainMenu m(&g);
    m.menu();
    return 0;
}