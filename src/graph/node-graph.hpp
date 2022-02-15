#ifndef NO_GRAFO
#define NO_GRAFO

#include <iostream>


/**
 * @brief 
 */
class NodeGraph {
friend class Graph;
private:
	int v; // o valor do vertice ou ordem é representado por um caracter
	int weight; //
public:
	/**
	 * @brief Construtor da classe NodeGraph
	 * 
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	NodeGraph();

	int getIndex() const;


	/**
	 * @brief Construtor da classe No Grafo
	 * 
	 * @param id numero que representa o vertice
	 * @param peso peso da aresta que chega ao vertice
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	NodeGraph(int v, int weight);


	/**
	 * @brief Sobrecarga do operador < necessária para impressão em stream
	 * 
	 * @param out stream para escrita, podendo ser um arquivo ou o terminal
	 * @param other A classe que contém os dados a serem impressos
	 * @return std::ostream& ponteiro implicíto para a stram,
	 * para continuar a impressão com <<
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	friend std::ostream& operator << (std::ostream &out, const NodeGraph& other);

	/**
	 * @brief Destrutor da classe NodeGraph
	 * 
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	~NodeGraph();
};


#endif // NO_GRAFO
