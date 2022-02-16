#include "graph.hpp"
#include "node-graph.hpp"
#include "../resume-file/singleton-resume-file.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>


void Graph::construct(std::istream& file) {
    std::string line;
    NodeGraph temp;
    int index;
    
    while (getline(file, line)){

        temp.v = atoi(&line[line.find_last_of('S') + 1]);
        index = atoi(&line[line.find_first_of('S')] + 1);
        temp.weight = atoi(&line[line.find_last_of(',')] + 1);
        auto greater = std::max(index, temp.v);
        if ((int)graph.size() > greater){
            graph[index].push_back(temp);
        }else{
            graph.resize(greater + 1);
            graph[index].push_back(temp);
        }
    }
    /*char enter = '\n';
    while (enter == '\n') {
        file >> enter;
        std::cout << "Li [" << enter << "]\n";
    }
    getline(file, line);
    line = enter + line;
    std::cout << line << '\n' ;*/
}

void Graph::read(const std::string &filename){
    std::ifstream file;
    file.open(filename);

    if(file.is_open()){
        construct(file);
    }else{
        std::cout << "arquivo " << filename << " invalido\n";
    }
    
    file.close();
}

void Graph::read() {
   
}

void Graph::printOrder() {
    auto it = order.cbegin();
    auto end = order.cend();
    end--;
    std::cout << "Caminho percorrido: ";
    for(; it != end; it++){
        std::cout << 'S' << *it << " - ";
    }
    std::cout << 'S' << *it << '\n';
}


Graph::Graph()
    : qnt_node(0),
    colors(nullptr),
    dist(nullptr) {
}

int Graph::readIndex() {
    int ret = -1;
    std::string input;
    std::cin >> input;
    std::cin.ignore(2, '\n');
    if (tolower(input[0]) == 's') {
        const char *ptr = input.c_str();
        ret = std::atoi(ptr + 1);
    }
    return ret;
}


bool Graph::validIndex(int index){
    return index >= 0 && index < (int)graph.size();
}


void Graph::show() {
    for (int i = 0; i < (int)graph.size(); i++) {
        std::cout << "Vértices adjacentes a " << 'S' <<  i << ": ";
        for(const auto &it : graph[i]){
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }
}



void Graph::cleanTemp(){
    if (colors != nullptr) {
        delete[] colors;
        colors = nullptr;
    }
    if (dist != nullptr) {
        delete[] dist;
        dist = nullptr;
    }
    order.clear();
}

void Graph::DFSVisit(int index, int end) {
    
    order.push_back(index);
    std::cout << "Na sala: " << 'S' <<  index << '\n';
    if(index == end) {
        find_end = true;
        std::cout << "\nSala final encontrado!!!!\n\n";
        return;
    }
    colors[index] = CINZA;
    for(auto it : graph[index]) {
        if (colors[it.getIndex()] == BRANCO && (!find_end)){
            DFSVisit(it.getIndex(), end);
        }
    }
    colors[index] = PRETO;
}

void Graph::DFS(int begin, int end) {
    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file << "\n\nBusca em Profundidade\n\n";
    {
    SET_TIMER;
    
    int i;
    colors = new color[graph.size()];
    find_end = false;

    for(i = 0; i < (int)graph.size(); i++) {
        colors[i] = BRANCO;
    }


    for(i = begin; i < (int)graph.size(); i++) {
        if (colors[i] == BRANCO && (!find_end)) {
            DFSVisit(i, end);
        }
    }
    if (order.back() != end){
        std::cout << "\nSala nao encontrada.\n\n"; 
    }
    }
    
    printOrder();
    std::cout << "Numero de salas visitadas: " << order.size() << '\n';
  
    
    file << "Caminho percorrido pelo algoritmo: ";
    for (auto i : order){
        file << 'S' << i << ' '; 
    }
    file << '\n';
    file << "Numero de salas visitadas: ";
    file << order.size() << '\n';
    cleanTemp();
}

void Graph::BFS(int begin, int end) {
    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file << "\n\nBusca em Largura\n\n";
    {
    SET_TIMER;
    int i;
    colors = new color[graph.size()];
    std::list<int> q;

    for(i = 0; i < (int)graph.size(); i++) {
        colors[i] = BRANCO;
    }
    
    q.push_back(begin);
    colors[begin] = CINZA;
    std::cout << '\n';
    int first;
    while (!q.empty()){
        first = q.front();
        std::cout << "Na sala: " << 'S' <<  first << '\n';
        if (first == end){
            std::cout << "\nSala final encontrado!!!!\n\n";
            order.push_back(end);
            break;
        }
        for(const auto &it : graph[first]){
            const int adj = it.getIndex();
            if (colors[adj] == BRANCO){
                colors[adj] = CINZA;
                q.push_back(adj);
            }
        }
        order.push_back(q.front());
        q.pop_front();
        colors[first] = PRETO;
    }
    if (order.back() != end){
        std::cout << "\nSala nao encontrada.\n\n"; 
    }
    
    }
    printOrder();
    std::cout << "Numero de salas visitadas: " << order.size() << '\n';

    file << "Caminho percorrido pelo algoritmo: ";
    for (auto i : order){
        file << 'S' << i << ' '; 
    }
    file << '\n';
    file << "Numero de salas visitadas: ";
    file << order.size() << '\n';
    cleanTemp();
}

/**
 * @brief Utilizado para mostrar na tela o caminho de um
 * vertice origem até um vertice fim utilizando a lista de
 * predecessores
 *
 * Utilizado no algoritimo de BellMan-Ford
 * @param begin vertice que inicia o caminho
 * @param fim vertice que acaba o caminho
 * @pre vetor de predecessores alocado
 * @post Caminho impresso na tela
 */
bool Graph::printCaminho(int begin, int fim, int &salas) {
    if (begin == fim) {
        //std::cout << fim;
		order.push_back(fim);
        return true;
    }
    if (begin == NIL || predecessores[begin] == NIL) {
        std::cout << "Inacessível";
        return false;
    }
	salas++;
    const auto ret = printCaminho(predecessores[begin], fim, salas);
	order.push_back(begin);
	return ret;
}

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
bool Graph::relax(const int inicio, const int fim, const int weight) {
	if (dist[fim] > (dist[inicio] + weight)) {
        dist[fim] = dist[inicio] + weight;
        predecessores[fim] = inicio;
        return true;
    }
    return false;
}

/**
 * @brief Executa o algorítimo de BellMan-Ford
 *
 * Algorítmo que encontra o menor caminho de todos os vértices em
 * relação ao vertice passado como argumento
 * @param vertice_begin o vértice para qual todos os outros devem
 * encontrar o menor caminho
 * @return true Caso o Grafo não possua um cíclo negativo
 * @return false Caso o Grafo possua um cíclo negativo
 * @pre vértice de início está contido no Grafo,
 *      Grafo deve ser orientado,
 * @post Nenhuma
 */
bool Graph::BellmanFord(int begin, int end) {
    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file << "\n\nBusca em Largura\n\n";
    bool ret;
	{
	SET_TIMER;
	int i, qnt;
	const int size = (int)graph.size();
    predecessores = new int[size];
    dist		  = new int[size];

	for(int i = 0; i < size; i++) {
        predecessores[i] = NIL;
        dist[i] = MAX_DIST;
    }
    dist[begin] = 0;

    for (qnt = 0; qnt < (size - 2); qnt++) {
        ret = false;
        // percorre cada uma das arestas
        for(i = 0; i < size; i++) {
			for (const auto &it : graph[i]) {
				if (relax(i, it.v, it.weight)) {
					ret = true;
				}
			}
        }
        // se não teve nenhum relax nessa interação por todas as arestas
        // pare de executar o algoritmo
        if (!ret) {
            break;
        }
    }

    // percorre cada uma das arestas, buscando ciclo negativo
    ret = true;
    for(i = 0; i < size; i++) {
		for (auto it : graph[i]) {
            if (dist[it.v] > dist[i] + it.weight) {
                ret = false;
                break;
            }
		}
    }
	}

    if (ret) {
        int salas;
        printCaminho(end, begin, salas);
        printOrder();
        std::cout << "Numero de salas visitadas: " << order.size() << '\n';

        file << "Caminho percorrido pelo algoritmo: ";
        for (auto i : order) {
            file << 'S' << i << ' ';
        }
        file << '\n';
        file << "Numero de salas visitadas: ";
        file << order.size() << '\n';

    }else {
        std::cout << "O Grafo Possui ciclo negativo" << std::endl;
    }

    delete[] dist;
    delete[] predecessores;
    return ret;
}



Graph::~Graph() {
    
}
