#include "array.h"
#include "single.h"
#include <stdio.h>

template <typename T>
class AdjacencyList {
private:
    MyArray<Linkedlist<T>> list;
    int numVertices;

public:
    AdjacencyList(int vertices) : numVertices(vertices), list(vertices) {}

    void add_edge(int fromVertex, int toVertex, T weight) {
        list[fromVertex].insert(weight);
        // Uncomment the following line for an undirected graph
        // list[toVertex].insert(weight);
    }

    Linkedlist<T>& get_neighbors(int vertex) {
        return list[vertex];
    }
};

int main(){
    AdjacencyList<int> adjList(4);
    adjList.add_edge(0, 1, 1);
    adjList.add_edge(0, 2, 2);
    adjList.add_edge(1, 2, 3);

    Linkedlist<int>& neighbors = adjList.get_neighbors(0);
    Linkedlist<int>::Node* currentNode = neighbors.begin();
    std::cout << "Neighbors of vertex 0: ";
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;

    return 0;
}