#ifndef NO_GRAFO
#define NO_GRAFO

#include <iostream>


/**
 * @brief 
 */
class NodeGraph {
friend class Grafo;
private:
	int id, peso;
public:
	/**
	 * @brief Construtor da classe NodeGraph
	 * 
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	NodeGraph();

	/**
	 * @brief Construtor da classe No Grafo
	 * 
	 * @param id numero que representa o vertice
	 * @param peso peso da aresta que chega ao vertice
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	NodeGraph(int id, int peso);

	/**
	 * @brief Sobrecarga do operador < necessária para ordenação
	 * 
	 * faz a comparação a partir do id do vértice
	 * @param other 
	 * @return true se this->id é maior
	 * @return false se other.id é maior
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	bool operator < (const NodeGraph& other);

	/**
	 * @brief Sobrecarga do operador < necessária para std::find
	 * 
	 * faz a comparação a partir do id do vértice
	 * @param other o id de um no
	 * @return true se other é igual ao id do vertice
	 * @return false se other é diferente ao id do vertice
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	bool operator == (int other);

	/**
	 * @brief Sobrecarga do operador < necessária para std::find
	 * 
	 * faz a comparação a partir do id do vértice
	 * @param other o outro no
	 * @return true se other é igual ao id do vertice
	 * @return false se other é diferente ao id do vertice
	 * @pre Nenhuma
	 * @post Nenhuma
	 */
	bool operator == (const NodeGraph &other);

	bool operator >= (const NodeGraph &other);

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