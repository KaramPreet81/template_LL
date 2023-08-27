#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

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

           
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        
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
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            
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

    void deque() {
        if (size > 0) {
            for (int i = 0; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            --size;
        }
    }

    int getSize() const {
        return size;
    }

    T getElementAt(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    bool isEmpty() const {
        return size == 0;
    }
};
};

#endif
