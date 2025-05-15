#include <bits/stdc++.h>

using namespace std;


class Graph {  
    private:
        unordered_map<string, unordered_set<string> > adjList;
    
    public:

        void addVertex(string vertex) {
            adjList[vertex];
        }

        bool addEdge(string vertex1, string vertex2) {
            if(adjList.count(vertex1) != 0 and adjList.count(vertex2) != 0) {
                adjList.at(vertex1).insert(vertex2);
                adjList.at(vertex2).insert(vertex1);
                return true;
            }
            return false;
        }

        bool removeEdge(string vertex1, string vertex2) {
            if(adjList.count(vertex1) != 0 and adjList.count(vertex2) != 0) {
                // Erase vai remover o valor do vertice 2 do vertice1
                adjList.at(vertex1).erase(vertex2);
                adjList.at(vertex2).erase(vertex1);
                return true;
            }
            return false;
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

    newGraph->addVertex("A");
    newGraph->addVertex("B");
    newGraph->addVertex("C");

    newGraph->addEdge("A", "B");
    newGraph->addEdge("A", "C");

    newGraph->printGraph();
    
    cout << "Após remover o vértice: " << endl;

    newGraph->removeEdge("C", "A");

    newGraph->printGraph();
    return 0;
}
