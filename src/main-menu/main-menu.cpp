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

void MainMenu::pause(const char * optional_message) const {
    if (optional_message != nullptr) {
        std::cout << optional_message;
    }
    std::cout << "\nPrecione qualquer caractere para continuar\n";
    cleanBuffer();
}

void MainMenu::cleanBuffer() const {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void MainMenu::cleanScreen() const {
    int temp __attribute__((unused)) = system(CLEAR);
}

 void MainMenu::showAlgorithms() const{
     using namespace std;
     cout    <<"|-------------------------------------------------------|\n"
            << "|                  Algoritmos de Busca                  |\n"
            << "|-------------------------------------------------------|\n"
            << "|                                                       |\n"
            << "|               1.  Busca em Largura                    |\n"
            << "|               2.  Busca em Profundidade               |\n"
            << "|               3.  A*                                  |\n"
            << "|               4.  Relatório dos algoritmos            |\n"
            << "|               5.  Voltar                              |\n"
            << "|-------------------------------------------------------|\n\n\n";
 }

void MainMenu::runGraphAlgirithm() {
    using namespace std;
    std::string input;
    int begin, end;
    char entrada=0;

    while (true){
        cleanScreen();
        showAlgorithms();
        entrada = getchar();
        cleanBuffer();
        
        switch (entrada){
        case '1':
            //largura
            if (g->graph.empty()) {
                pause("Grafo não inicializado\n");return;
            }
            std::cout << "Digite a sala inicial: ";
            begin = Graph::readIndex();
            while (!g->validIndex(begin)) {
                std::cout << "Sala inicial inválida. Digite novamente: \n";
                begin = Graph::readIndex();
            }
            std::cout << "Digite a sala final: ";
            end = Graph::readIndex();
            while (!g->validIndex(end)) {
                std::cout << "Sala final inválida. Digite novamente: \n";
                end = Graph::readIndex();
            }
            g->BFS(begin, end);
            pause();
            break;
        
        case '2':
            //profundidade
            if (g->graph.empty()) {
                pause("Grafo não inicializado\n");return;
            }
            std::cout << "Digite a sala inicial: ";
            begin = Graph::readIndex();
            while (!g->validIndex(begin)) {
                std::cout << "Sala inicial inválida. Digite novamente: \n";
                begin = Graph::readIndex();
            }
            std::cout << "Digite a sala final: ";
            end = Graph::readIndex();
            while (!g->validIndex(end)) {
                std::cout << "Sala final inválida. Digite novamente: \n";
                end = Graph::readIndex();
            }
            g->DFS(begin, end);
            pause();
            break;

        case '3':
            
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

std::string MainMenu::readFilePath(){
    std::string filename;
    std::cout << "Entre com o nome do arquivo: ";
    std::cin >> filename;
    std::cout << filename << '\n';
    cleanBuffer();
    return filename;
}

void MainMenu::menu() {
    using namespace std;

    int entrada = 0;
    while (true){
        cleanScreen();
        show();
        entrada = getchar();
        cleanBuffer();
        
        switch (entrada){
        case '1':
            g->read(readFilePath());
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

