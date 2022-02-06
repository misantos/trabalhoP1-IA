#include "main-menu.hpp"
#include "../graph/node-graph.hpp"

MainMenu::MainMenu() : g(nullptr) {
}

MainMenu::MainMenu(Graph *g) {
    this->g = g;
}

bool MainMenu::addSourceGraph(Graph *g) {
    if (this->g == nullptr) {
        this->g = g;
        return true;
    }
    std::cerr << "Falha ao adicionar grafo, já estava carregado\n";
    return false;
}

void MainMenu::pause() const {
    std::cout << "\nPrecione qualquer caractere para continuar\n";
    cleanBuffer();
}

void MainMenu::cleanBuffer() const {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void MainMenu::cleanScreen() const {
    int temp __attribute__((unused)) = system(CLEAR);
}

void MainMenu::runGraphAlgirithm() {
    if (g->graph.empty()) {
        std::cerr << "Grafo não inicializado\n";
        pause();
        return;
    }
    int begin, end;
    char entrada;
    std::cout << "Busca em profundidade\n";
    std::cout << "Digite o vértice inicial: ";
    std::cin >> begin;
    while (!g->validIndex(begin)) {
        std::cout << "Sala inicial inválida. Digite novamente: \n";
        std::cin >> begin;
    }
    std::cout << "Digite a sala final: ";
    std::cin >> end;
    while (!g->validIndex(end)) {
        std::cout << "Sala final inválida. Digite novamente: \n";
        std::cin >> end;
    }
    g->DFS(begin, end);
    pause();
}

void MainMenu::show() const {
    using namespace std;
    cout    << "|-------------------------------------------------------|\n"
            << "|                  Menu Principal                       |\n"
            << "|-------------------------------------------------------|\n"
            << "|           Caminho de personagens em Jogos:            |\n"
            << "|                                                       |\n"
            << "|               1.  Leitura do arquivo                  |\n"
            << "|               2.  Leitura do arquivo com heuristicas  |\n"
            << "|               3.  Algoritmos de Busca                 |\n"
            << "|               4.  Mostrar Grafo                       |\n"
            << "|               5.  Sair                                |\n"
            << "|-------------------------------------------------------|\n\n\n";
}

void MainMenu::menu() {
    using namespace std;

    int begin, end;
    int entrada = 0;
    while (entrada != MENU_FUNCTIONS){
        cleanScreen();
        show();
        entrada = getchar();
        cleanBuffer();
        
        switch (entrada){
        case '1':
            g->read();
            break;
        
        case '2':
            //g->read...
            break;

        case '3':
            runGraphAlgirithm();
            pause();
            break;
        
        case '4':
            cleanScreen();
            g->show();
            pause();
            break;

        case '5':
            cout << "Fechando Menu\n";
            return;
        
        default:
            cout << "Opção inválida\n";
            break;
        }
    }
}

MainMenu::~MainMenu() {

}

