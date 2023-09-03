#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include "single.h"  

const int MAX_OPERATIONS = 100000;
const int MAX_VALUE = 1000;

int main() {
    //Solution<int>::MyArray dynamicArray;
    Solution<int>::Linkedlist linkedList;

    
    std::cout << "Insertion Time Comparison:\n";
    for (int probability = 0; probability <= 100; probability += 10) {
        auto start = std::chrono::high_resolution_clock::now();

        
        int numInsertions = MAX_OPERATIONS * probability / 100;
        for (int operation = 0; operation < MAX_OPERATIONS; ++operation) {
            if (operation < numInsertions) {
                //dynamicArray.InsertEnd(rand() % MAX_VALUE); 
                 linkedList.InsertEnd(rand() % MAX_VALUE); 
            } else {
               //dynamicArray.DelnodeAtend() ;
                linkedList.DelnodeAtend();
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        double elapsedTimeMs = static_cast<double>(duration.count()) / 1000.0;

        std::cout << "Probability: " << probability << "%, Time: " << elapsedTimeMs << " ms\n";
    }

    return 0;
}
