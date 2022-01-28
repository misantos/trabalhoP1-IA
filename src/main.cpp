#include "graph/graph.hpp"

int main(int argc, char *argv[]){
    Graph g;
    if (argc == 2) {
        std::cout << "entrando na funcao\n";
        g.read(argv[1]);
    }

    g.show();

    g.DFS('a', 'g');

    return 0;
}