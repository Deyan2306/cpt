#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> graph;

public:
    Graph(int vertices) : V(vertices), graph(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int source, int destination, int weight) {
        graph[source][destination] = weight;
        graph[destination][source] = weight; // If undirected
    }

    int minKey(const vector<int>& key, const vector<bool>& mstSet) {
        int min = INT_MAX, min_index = -1;

        for (int v = 0; v < V; ++v) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }

    void primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> mstSet(V, false);

        key[0] = 0; // Start from the first node

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        cout << "Prim's Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.primMST();

    return 0;
}
