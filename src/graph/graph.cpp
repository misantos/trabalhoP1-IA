#include "graph.hpp"
#include "node-graph.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string_view>
#include <queue>


void Graph::construct(std::istream& file) {
    std::string line;
    //getline(file, line);
    //isOrientado = (line.substr(line.find_first_of('=') + 1) == "sim");

    //getline(file, line);
    //qnt_nos = atoi((line.substr(line.find_first_of('=') + 1)).c_str()); 
    //graph.resize(9);
    NodeGraph temp;
    int index;
    
    while (getline(file, line)){
        temp.v = line[11];
        index = line[8] - 'a';
        temp.weight = stoi(line.substr(14, line.size() - 16));
        if ((int)graph.size() > index){
            graph[index].push_back(temp);
        }else{
            graph.resize(index + 1);
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
        
        if (!isOrientado) {
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

Graph::Graph()
    : qnt_node(0),
    colors(nullptr),
    ancestor(nullptr),
    dist(nullptr) {
}


bool Graph::validIndex(int index){
    return index > 0 && index < (int)graph.size();
}

void Graph::read() {
    
}

void Graph::show() {
    for (int i = 0; i < (int)graph.size(); i++) {
        std::cout << "Vértices adjacentes a " << static_cast<char>(i + 'a') << ": ";
        for(const auto &it : graph[i]){
            std::cout << it << ' ';
        }
        std::cout << '\n';
    }
}

int Graph::countEdge() {
    
}

void Graph::cleanTemp(){
    if (colors != nullptr) {
        delete[] colors;
        colors = nullptr;
    }
    if (ancestor != nullptr) {
        delete[] ancestor;
        ancestor = nullptr;
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
    SET_TIMER;
    int i;
    begin -= 'a';
    end -= 'a';
    colors = new color[graph.size()];
    find_end = false;

    for(i = 0; i < (int)graph.size(); i++) {
        colors[i] = BRANCO;
    }
    std::cout << "entrando no for \n";
    for(i = begin; i < (int)graph.size(); i++) {
        if (colors[i] == BRANCO && (!find_end)) {
            std::cout << "anted do dfsvisit \n";
            DFSVisit(i, end);
        }
    }

    printOrder();
    cleanTemp();
}

void Graph::BFS(int begin, int end) {
    SET_TIMER;
    int i;
    begin -= 'a';
    end -= 'a';
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
        if (first == end){
            std::cout << "objetivo final encontrado\n";
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
    printOrder();
    cleanTemp();
}



Graph::~Graph() {
    
}
