#include "graph.hpp"
#include "node-graph.hpp"
#include "../resume-file/singleton-resume-file.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>


void Graph::construct(std::istream& file) {
    graph.resize(1);
    graph[0] = std::list<NodeGraph>();
    std::string line;
    NodeGraph temp;
    int index;
    std::cout << "func\n";
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
    for(; it != end; it++){
        std::cout << static_cast<char>('S') << *it << " - ";
    }
    std::cout << static_cast<char>('S') << *it << '\n';
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
        std::cout << "Vértices adjacentes a " << static_cast<char>('S') <<  i << ": ";
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
    std::cout << "inserindo " << index << "\n";
    if(index == end) {
        find_end = true;
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
    // set timer, numero de salas visitadas (order.size), quantas vezes a funcao recursiva foi chamada
    
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
    }
    
    printOrder();
    std::cout << "Numero de salas visitadas: " << order.size() << '\n';
  
    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file << "\n\nBusca em Profundidade\n\n";
    file << "Caminho percorrido pelo algoritmo: ";
    for (auto i : order){
        file << 'S' << i << ' '; 
    }
    file << '\n';
    file << "Numero de salas visitadas: ";
    file << order.size();
    cleanTemp();
}

void Graph::BFS(int begin, int end) {
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
    
    int first;
    while (!q.empty()){
        first = q.front();
        std::cout << "\n\n" << static_cast<char>('S') <<  i << ": ";
        if (first == end){
            std::cout << "\nSala final encontrado!!!!\n";
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
    }
    printOrder();
    std::cout << "Numero de salas visitadas: " << order.size() << '\n';

    SingletonResumeFile &file = SingletonResumeFile::getInstance();
    file << "\n\nBusca em Largura\n\n";
    file << "Caminho percorrido pelo algoritmo: ";
    for (auto i : order){
        file << 'S' << i << ' '; 
    }
    file << '\n';
    file << "Numero de salas visitadas: ";
    file << order.size();
    cleanTemp();
}

Graph::~Graph() {
    
}
