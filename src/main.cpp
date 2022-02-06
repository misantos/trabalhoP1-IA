#include "graph/graph.hpp"
#include "main-menu/main-menu.hpp"

int main(int argc, char *argv[]){
    Graph g;
    if (argc == 2) {
        std::cout << "entrando na funcao\n";
        g.read(argv[1]);
    }
    MainMenu m(&g);
    m.menu();
    //g.show();
    //std::cout << "dfs \n";
    //g.DFS('a', 'e');

    //g.BFS('a', 'e');
    

    return 0;
}