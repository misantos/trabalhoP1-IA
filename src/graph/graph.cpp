#include "graph.hpp"
#include "node-graph.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string_view>


void Graph::construct(std::istream& file) {
    std::string line;
    //getline(file, line);
    //isOrientado = (line.substr(line.find_first_of('=') + 1) == "sim");

    //getline(file, line);
    //qnt_nos = atoi((line.substr(line.find_first_of('=') + 1)).c_str()); 
    graph.resize(9);
    NodeGraph temp;
    int index;
    std::cout << "antes do while\n";

    while (getline(file, line)){
        temp.v = line[11];
        index = line[8] - 'a';
        temp.weight = stoi(line.substr(14, line.size() - 16));
        if (graph.size() > index){
            graph[index].push_back(temp);
        }else{
            graph.resize(index);
            graph[index].push_back(temp);
        }
        
    }
    

    /*while (getline(file, line)) {
        temp.v = line[11];
        std::cout << "dentro do while" << temp;
        std::string w(line.begin() + line.find_last_of(',') + 1, line.begin() + line.find_last_of(')')) ;
        std::cout << "dentro do while" << w;
        temp.weight = atoi(w.c_str());
        index = line[9] - 'a';   
        graph[index].push_back(temp);
        
        /*if (!isOrientado) {
            std::swap(index, temp.id);
            grafo[index].insereOrdenado(temp);
        }*/
        //atoi(&line[line.find_first_of(',') + 1]);
    //}
}

void Graph::read(std::string filename){
    std::ifstream file;
    file.open(filename);

    if(file.is_open()){
        std::cout << "entrando na funcao construct\n";
        construct(file);
    }else{
        std::cout << "arquivo " << filename << " invalido\n";
    }
    

    file.close();
}



void Graph::printOrder() {
    auto it = order.cbegin();
    auto end = order.cend();
    end--;
    for(; it != end; it++){
        std::cout << static_cast<char>(*it + 'a') << " - ";
    }
    std::cout << static_cast<char>(*it + 'a') << '\n';
}

void Graph::printAncestor() {
    
}

void Graph::printDist() {
    
}

void Graph::printPath(int begin, int end) {
    
}

int Graph::getDistPath(int begin, int end) {
    
}

Graph::Graph() {
    
}

void Graph::read() {
    
}

void Graph::show() {
    for (int i = 0; i < graph.size(); i++) {
        std::cout << "Vértices adjacentes a " << static_cast<char>(i + 'a') << ": ";
        for(const auto &it : graph[i]){
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }
}

int Graph::countEdge() {
    
}

void Graph::DFSVisit(int index) {
    order.push_back(index);
    colors[index] = CINZA;
    for(auto it : graph[index]) {
        if (colors[it.getIndex()] == BRANCO){
            DFSVisit(it.getIndex());
        }
    }
    colors[index] = PRETO;
    
}

void Graph::DFS(int begin, int end) {
    int i;
    begin -= 'a';
    end -= 'a';
    colors = new color[graph.size()];

    for(i = 0; i < graph.size(); i++) {
        colors[i] = BRANCO;
    }

    for(i = begin; i < graph.size(); i++) {
        if (colors[i] == BRANCO) {
            DFSVisit(i);
        }
    }

    printOrder();
    
    delete[] colors;
}

void Graph::BFS(int begin, int end) {
    
}



Graph::~Graph() {
    
}
