#pragma once

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

template <class HeapType>
class Heap {
public:
    Heap(HeapType*, int32_t);
    explicit Heap(int32_t);
    ~Heap();

    void heapify();

    void insert(HeapType key);
    HeapType remove(int32_t pos = 0);

    void sort();

    bool isEmpty();

    int32_t getElements() { return nElements; };

private:
    void fixHeap(int32_t root);

    HeapType
        * data;
    int32_t
        nElements,
        capacity;
};

#include "MinHeap-implementation.hpp"