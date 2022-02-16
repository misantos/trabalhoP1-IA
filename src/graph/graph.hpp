#ifndef GRAFO
#define GRAFO

#include <algorithm>
#include <fstream>
#include <string>
#include <climits>
#include <list>
#include <vector>
#include <fstream>
#include <time.h>
#include "node-graph.hpp"


#include "../performance-algorithms/scope-timer.hpp"

/**
 * @brief enumera todas as cores possiveis que um vértice
 * pode assumir, criando assim o tipo (cor)
 */
enum color {
    BRANCO,
    CINZA,
    PRETO
};

/**
 * @brief define o valor que representa o Nulo para os algoritmos
 * 
 * utilizado em:
 *  - Busca em profundidade
 *  - Busca em largura
 */
#define NIL -1

/**
 * @brief Distancia máxima possível que não causa overflow em um int
 */
#define MAX_DIST ((INT_MAX/4) - 1)

/**
 * @brief Classe que representa um único grafo,
 * que sabe encapsula todos os métodos necessários
 * para a operação do mesmo
 * 
 * Utiliza a representação Listas de Adjacência
 */
class Graph {
    friend class MainMenu;
    private:

    bool find_end;
   
    int qnt_node;  /// inteiro que indica a quantidade de vértices do grafo
    
    std::vector<std::list<NodeGraph>> graph;  /// vetor de listas de vértices

    color *colors;  /// vetor de cores, alocado somente quando tem busca em
    /// profundidade ou largura

    int *dist;  /// vetor que informa a distância do vértice até a origem

    int *predecessores;  /// vetor de predecessores

    std::list<int> order;  /// vetor que informa a ordem em que os vértices
    /// foram acessados, bom saber o caminho que o algoritmo percorreu

    /**
     * @brief Constrói um grafo a partir de dados de entrada
     * 
     * @param in uma stream, podendo ser cin ou um arquivo
     * @pre uma stream de entrada válida
     * @post Grafo alocado e contendo os dados da stream
     */
    void construct(std::istream& in);

    /**
     * @brief Imprime a lista que contém a ordem de acesso dos vértices
     *
     * @pre lista ordem alocada
     * @post lista impressa na saída padrão
     */
    void printOrder();

    /**
     * @brief Imprime o vetor de distâncias
     * 
     * @pre vetor de distâncias alocada
     * @post vetor de distâncias impressa na saída padrão
     */
    void printDist();

        /**
     * @brief Utilizado para mostrar na tela o caminho de um
     * vertice origem até um vertice fim utilizando a lista de
     * predecessores
     * 
     * Utilizado no algoritmo de BellMan-Ford
     * @param inicio vértice que inicia o caminho
     * @param fim vértice que acaba o caminho
     * @pre vetor de predecessores alocado
     * @post Caminho impresso na tela
     */
    void printCaminho(int inicio, int fim);

    /**
     * @brief Informa a distância entre o vértice início e fim
     * 
     * Utilizado no algoritmo de BellMan-Ford
     * @param inicio vértice de início
     * @param fim vértice de fim
     * @return int distância entre o vértice início e fim
     * @pre Vetor de distância e predecessores carregados
     * @post Nenhuma
     */
    int getDistCaminho(int inicio, int fim);

    /**
     * @brief Inicializa o vertice de origem
     *
     * Utilizado no algoritmo de Bellman-Ford
     * @pre predecessores e dist inicializados
     * @post vértice de origem e suas estruturas auxiliares
     * inicializadas
     */
    void inicializaOrigem(int origem);

    /**
     * @brief Diminui o limite superior do peso do menor caminho
     * 
     * Utilizado no algoritmo de Bellman-Ford
     * @param inicio vértice que inicia o caminho
     * @param fim vértice que acaba o caminho
     * @pre Um algoritmo de menor caminho estar sendo executado
     * com suas estruturas alocadas
     * @post menor peso entre início e fim
     */
    bool relax(const int inicio, const int fim, const int peso);


    /**
     * @brief Informa a distância entre o vértice início e fim
     * 
     * Utilizado no algoritmo de BellMan-Ford
     * @param begin vértice de início
     * @param end vértice de fim
     * @return int distância entre o vértice início e fim
     * @pre Vetor de distância e predecessores carregados
     * @post Nenhuma
     */
    int getDistPath(int begin, int end);

    public:
    /**
     * @brief Construtor da classe Grafo
     * 
     * @pre Nenhuma
     * @post Nenhuma
     */
    Graph();

    static int readIndex();

    bool validIndex(int index);

    /**
     * @brief Cria o grafo com as informações contidas no arquivo
     * 
     * ver a função constroi
     * @param filename o nome do arquivo a ser lido
     * @pre filename contem um nome de arquivo valido e grafo desalocado
     * @post Grafo inicializado com os dados
     */
    void read(const std::string &filename);

    /**
     * @brief Cria o grafo com as informações recebidas da entrada padrão
     *
     * @pre Grafo desalocado
     * @post Nenhuma
     */
    void read();

    /**
     * @brief Imprime os grafos, em um formato de lista de adjacência
     * 
     * @pre Nenhuma
     * @post Nenhuma
     */
    void show();


    void cleanTemp();

    //----------------- Algoritmos de um grafo -----------------//

    /**
     * @brief Visita os vértices a partir de um ponto inicial e final,
     * seguindo o algoritmo de busca em largura
     * 
     * @param begin deve estar dentro dos limites do vértice
     * @pre Grafo inicializado com ler
     * @post ordem de visitação vértices impressa na saída padrão
     */
    void BFS(int begin, int end);

     /**
     * @brief Explora um vértice de cor branca, visitando recursivamente
     * todos os vértices adjacentes
     *
     * @param index Vértice a ser explorado, cor branca
     * @pre Somente chamado pela buscaEmProfundidade
     * @post Vértice index totalmente explorado, cor preto
     */
    void DFSVisit(int index, int end);

    /**
     * @brief Visita os vértices a partir de um ponto inicial e final,
     * seguindo o algoritmo de busca em profundidade
     * 
     * @param begin deve estar dentro dos limites do vértice
     * @pre Grafo inicializado com ler
     * @post ordem de visitação vértices impressa na saída padrão
     */
    void DFS(int begin, int end );

    /**
     * @brief Executa o algoritmo de BellMan-Ford
     *
     * Algoritmo que encontra o menor caminho de todos os vértices em
     * relação ao vértice passado como argumento
     * @param vertice_inicio o vértice para qual todos os outros devem
     * encontrar o menor caminho
     * @return true Caso o Grafo não possua um ciclo negativo
     * @return false Caso o Grafo possua um ciclo negativo
     * @pre vértice de início está contido no Grafo,
     *      Grafo deve ser orientado,
     *      Grafo carregado
     * @post Nenhuma
     */
    bool BellmanFord(int vertice_inicio);

    /**
     * @brief Destrutor da classe Grafo
     * 
     * @pre Nenhuma
     * @post Nenhuma
     */
    ~Graph();
};

#endif // GRAFO
