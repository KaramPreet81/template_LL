#include "single.h"

template<typename T>
class Graph {
public:
    typename Solution<T>::Linkedlist *adjList; // Use typename here
    int vertices;

    Graph(int v) : vertices(v) {
        adjList = new typename Solution<T>::Linkedlist[vertices]; // Use typename here
    }

    void addEdge(int source, int destination) {
        adjList[source].InsertEnd(destination);
    }

    void bfsTraversal(int startVertex) {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }

        typename Solution<T>::Nodesingle *queue = nullptr;

        visited[startVertex] = true;
        std::cout << startVertex << " ";
        queue = adjList[startVertex].head;

        while (queue != nullptr) {
            int currentVertex = queue->val;
            queue = queue->next;

            typename Solution<T>::Nodesingle *temp = adjList[currentVertex].head;
            while (temp != nullptr) {
                if (!visited[temp->val]) {
                    visited[temp->val] = true;
                    std::cout << temp->val << " ";
                    typename Solution<T>::Nodesingle *newNode = new typename Solution<T>::Nodesingle;
                    newNode->val = temp->val;
                    newNode->next = nullptr;

                    if (queue == nullptr) {
                        queue = newNode;
                    } else {
                        typename Solution<T>::Nodesingle *tempQueue = queue;
                        while (tempQueue->next != nullptr) {
                            tempQueue = tempQueue->next;
                        }
                        tempQueue->next = newNode;
                    }
                }
                temp = temp->next;
            }
        }
    }

    void dfsTraversal(int startVertex, bool *visited) {
        std::cout << startVertex << " ";
        visited[startVertex] = true;

        Solution<int>::Nodesingle *temp = adjList[startVertex].head;
        while (temp) {
            int neighbor = temp->val;
            if (!visited[neighbor]) {
                dfsTraversal(neighbor, visited);
            }
             
            temp = temp->next;
        }
    }

    void performDFS(int startVertex) {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }

        std::cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        dfsTraversal(startVertex, visited);
        std::cout << std::endl;

        delete[] visited;
    }
};

int main() {
    int vertices = 6;
    Graph<int> g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    int startVertex = 0;
    std::cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    g.bfsTraversal(startVertex);
    cout<<endl ; 
    g.performDFS(startVertex) ;

    return 0;
}
