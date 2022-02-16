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
    cout  	<< "|-------------------------------------------------------|\n"
            << "|                  Algoritmos de Busca                  |\n"
            << "|-------------------------------------------------------|\n"
            << "|                                                       |\n"
            << "|               1.  Busca em Largura                    |\n"
            << "|               2.  Busca em Profundidade               |\n"
            << "|               3.  Bellman-Ford                        |\n"
            << "|               4.  Voltar                              |\n"
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
            std::cout << "\nBusca em Largura\n\n";
            std::cout << "Digite a sala inicial (exemplo: s1): ";
            begin = Graph::readIndex();
            while (!g->validIndex(begin)) {
                std::cout << "Sala inicial inválida. Digite novamente: \n";
                begin = Graph::readIndex();
            }
            std::cout << "Digite a sala final (exemplo: s1): ";
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
            std::cout << "\nBusca em Profundidade\n\n";
            std::cout << "Digite a sala inicial (exemplo: s1): ";
            begin = Graph::readIndex();
            while (!g->validIndex(begin)) {
                std::cout << "Sala inicial inválida. Digite novamente: \n";
                begin = Graph::readIndex();
            }
            std::cout << "Digite a sala final (exemplo: s1): ";
            end = Graph::readIndex();
            while (!g->validIndex(end)) {
                std::cout << "Sala final inválida. Digite novamente: \n";
                end = Graph::readIndex();
            }
            g->DFS(begin, end);
            pause();
            break;

        case '3':
            if (g->graph.empty()) {
                pause("Grafo não inicializado\n");return;
            }
            std::cout << "\nBusca de BellmanFord\n\n";
            std::cout << "Digite a sala inicial (exemplo: s1): ";
            begin = Graph::readIndex();
            while (!g->validIndex(begin)) {
                std::cout << "Sala inicial inválida. Digite novamente: \n";
                begin = Graph::readIndex();
            }
			std::cout << "Digite a sala final (exemplo: s1): ";
            end = Graph::readIndex();
            while (!g->validIndex(end)) {
                std::cout << "Sala final inválida. Digite novamente: \n";
                end = Graph::readIndex();
            }
            g->BellmanFord(begin, end);
            pause();
            break;

        case '4':
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
            << "|               2.  Algoritmos de Busca                 |\n"
            << "|               3.  Mostrar Grafo                       |\n"
            << "|               4.  Sair                                |\n"
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
            std::cout << "\nLeitura concluida com sucesso!\n";
            pause();
            break;

        case '2':
            runGraphAlgirithm();
            pause();
            break;
        
        case '3':
            cleanScreen();
            g->show();
            pause();
            break;

        case '4':
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

