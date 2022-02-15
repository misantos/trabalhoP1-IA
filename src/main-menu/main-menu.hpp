#ifndef MAIN_MENU
#define MAIN_MENU
#include <cstdio>
#include <climits>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include "../graph/graph.hpp"
#include "../graph/node-graph.hpp"

#define MENU_FUNCTIONS 5

class MainMenu {
private:
    Graph *g;
    void show() const;
    // espera um input do usuario para fechar
    void pause(const char * optional_message = nullptr) const;
    // limpa o terminal
    void cleanScreen() const;
    // limpa o cin
    void cleanBuffer() const;

    void runGraphAlgirithm();

    void showAlgorithms() const;

    std::string readFilePath();
public:
    MainMenu();//= delete;
    MainMenu(Graph *g);

    bool addSourceGraph(Graph *g);
    
    void menu();
    
    ~MainMenu();
};


#endif //main
