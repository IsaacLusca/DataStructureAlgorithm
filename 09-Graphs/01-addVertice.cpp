#include <bits/stdc++.h>

using namespace std;


class Graph {  
    private:
    // essa lista de adjacencia é representada por um mapa de conjuntos
    // onde a chave é o vertice e o valor é um conjunto de vertices adjacentes
        unordered_map<string, unordered_set<string> > adjList;
    // Representando essa linha: {"A", []}
    
    public:
        // Adicionar e remover em uma lista adjacencia é O(1)
        bool addVertice(string vertice) {
            if(adjList.count(vertice) == 0) {
                adjList[vertice];
                return true;
            }
            return false;
        }

        // Pode ser escrito como void:
        void addVertex(string vertex) {
            adjList[vertex];
        }

        void printGraph() {
            for (const auto& pair : adjList) {
                const string& vertex = pair.first;
                const unordered_set<string>& edges = pair.second;
                cout << vertex << ": [ ";
                for (auto edge: edges) {
                    cout << edge << " ";
                }
                cout << "]" << endl;
            }
        }
};


int main() {
    Graph* newGraph = new Graph();

    newGraph->addVertice("A");

    newGraph->printGraph();

    return 0;

}
