#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Graph class representing an undirected graph using adjacency list
class Graph {
private:
    int vertices; // Number of vertices in the graph
    vector<vector<int>> adjList; // Adjacency list representation

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V) : vertices(V), adjList(V) {}

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // Assuming undirected graph
    }

    // Depth-First Search algorithm
    void DFS(int startVertex) {
        // Create a boolean array to mark visited vertices
        vector<bool> visited(vertices, false);

        // Create a stack for DFS
        stack<int> dfsStack;

        // Push the starting vertex onto the stack
        dfsStack.push(startVertex);

        // Loop until the stack is empty
        while (!dfsStack.empty()) {
            // Pop a vertex from the stack and print it
            int currentVertex = dfsStack.top();
            dfsStack.pop();

            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            // Push all adjacent vertices that have not been visited
            for (const int& neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    dfsStack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "Depth-First Search starting from vertex 0:\n";
    g.DFS(0);

    return 0;
}
