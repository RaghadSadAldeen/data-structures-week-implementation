#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

class Graph {
    unordered_map<string, list<string>> adj;

public:
    void addVertex(const string& v) {
        adj[v]; // Ensures the key exists
    }

    void addEdge(const string& u, const string& v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void removeEdge(const string& u, const string& v) {
        adj[u].remove(v);
        adj[v].remove(u);
    }

    void removeVertex(const string& v) {
        for (auto& pair : adj)
            pair.second.remove(v);
        adj.erase(v);
    }

    void printGraph() {
        for (const auto& pair : adj) {
            cout << pair.first << ": ";
            for (const auto& neighbor : pair.second)
                cout << neighbor << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");

    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.printGraph();

    cout << "Remove edge A-C\n";
    g.removeEdge("A", "C");
    g.printGraph();

    cout << "Remove vertex B\n";
    g.removeVertex("B");
    g.printGraph();

    return 0;
}
