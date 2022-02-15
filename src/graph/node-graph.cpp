#include "node-graph.hpp"

/**
 * @brief Construtor da classe NodeGraph
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
NodeGraph::NodeGraph() {
    //debug("Construindo um No, sem parametros\n");
    this->v = 0;
    this->weight = 0;
}

/**
 * @brief Construtor da classe No Grafo
 *
 * @param id numero que representa o vertice
 * @param peso peso da aresta que chega ao vertice
 * @pre Nenhuma
 * @post Nenhuma
 */
NodeGraph::NodeGraph(int v, int weight) {
    //debug("Construindo um No, com parametros\n");
    this->v = v;
    this->weight = weight;
}

int NodeGraph::getIndex() const {
    return v;//- 'a';
}

/**
 * @brief Sobrecarga do operador << necessária para impressão em stream
 * imprime num arquivo os dados do nó
 * @param out stream para escrita, podendo ser um arquivo ou o terminal
 * @param other A classe que contém os dados a serem impressos
 * @return std::ostream& ponteiro implicíto para a stram,
 * para continuar a impressão com <<
 * @pre Nenhuma
 * @post Nenhuma
 */


std::ostream& operator << (std::ostream &out, const NodeGraph& other) {
    //out << '[' << other.id << ", " << other.peso << ']';
    out << '[' << other.v << ']';
    return out;
}

/**
 * @brief Destrutor da classe NodeGraph
 *
 * @pre Nenhuma
 * @post Nenhuma
 */
NodeGraph::~NodeGraph() {
    //debug("Destruindo o No\n");
}
