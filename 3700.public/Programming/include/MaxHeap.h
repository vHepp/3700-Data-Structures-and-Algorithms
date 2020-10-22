//
// Created by bob on 11/14/19.
//

#pragma once

#include <cstdint>

template <class HeapType>
class Heap {
public:
    Heap(HeapType *,int32_t);
    explicit Heap(int32_t);
    ~Heap();

    void heapify();

    void insert(HeapType key);
    HeapType remove(int32_t pos=0);

    void sort();
private:
    void fixHeap(int32_t root);

    HeapType
        *data;
    int32_t
        nElements,
        capacity;
};

#include "MaxHeap-implementation.h"