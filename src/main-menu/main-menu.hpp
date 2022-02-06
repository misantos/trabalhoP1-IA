#ifndef MAIN_MENU
#define MAIN_MENU
#include <cstdio>
#include <climits>

#define CLEAR "clear"
#include "../graph/graph.hpp"
#include "../graph/node-graph.hpp"

#define MENU_FUNCTIONS 5

class MainMenu {
private:
    Graph *g;
    void show() const;
    void pause() const;
    void cleanScreen() const;
    void cleanBuffer() const;

    void runGraphAlgirithm();
public:
    MainMenu();
    MainMenu(Graph *g);

    bool addSourceGraph(Graph *g);
    
    void menu();
    
    ~MainMenu();
};


#endif //main