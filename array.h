#ifndef ARRAY.H
#define ARRAY.H

#include<iostream>
#include<stdio.h> 

using namespace std ;
template <typename T>
class Solution{
public:    


class MyArray {
private:
    T* data;
    int size;
    int capacity;

public:
    MyArray() : data(nullptr), size(0), capacity(0) {}

    MyArray(int initialCapacity) : data(new T[initialCapacity]), size(0), capacity(initialCapacity) {}

    ~MyArray() {
        delete[] data;
    }

    void insert(T value) {
        if (size == capacity) {
            // Double the capacity if the array is full
            int newCapacity = capacity == 0 ? 1 : capacity * 2;
            T* newData = new T[newCapacity];

            // Copy elements from the old array to the new array
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            // Delete the old array and update data and capacity
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        // Insert the new element and increase the size
        data[size] = value;
        ++size;
    }

    void remove(T value) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            // Shift elements to the left to overwrite the removed element
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            // Decrease the size after removing the element
            --size;
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void pop() {
        if (size > 0) {
            --size;
        }
    }

    void deque()
    {
        int index = 0 ; 
        if(index < size)
        {
            std::cout<< data[index] ; 
        }
        size--  ; 
    }
};


};

#endif  