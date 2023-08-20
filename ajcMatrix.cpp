
#include "single.h"
#include <stdio.h>

using namespace std ; 

class Graph {
private:
    int numVertices;
    Linkedlist<int>* adjacencyList;  // Replace Linkedlist<int> with your actual Linkedlist class

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList = new Linkedlist<int>[vertices];
    }

    void add_edge(int fromVertex, int toVertex) {
        adjacencyList[fromVertex].InsertEnd(toVertex);
        // Uncomment the following line for an undirected graph
        // adjacencyList[toVertex].InsertEnd(fromVertex);
    }

    // BFS traversal
    void BFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            visited[i] = false;
        }

        Linkedlist<int> queue;
        visited[startVertex] = true;
        queue.InsertEnd(startVertex);

        while (!queue.isEmpty()) {
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.DelnodeAtend();

            Nodesingle<int>* temp = adjacencyList[currentVertex].head;
            while (temp) {
                int neighbor = temp->val;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.InsertEnd(neighbor);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }
};

int main() {
    int numVertices = 5;  // Replace with the actual number of vertices
    Graph graph(numVertices);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);
    graph.add_edge(2, 3);
    graph.add_edge(3, 3);

    std::cout << "BFS traversal starting from vertex 2: ";
    graph.BFS(2);
    std::cout << std::endl;

    return 0;
}
