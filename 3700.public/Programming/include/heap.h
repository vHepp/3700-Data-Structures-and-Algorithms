//
// Created by bob on 11/14/19.
//

#pragma once

#include <cstdint>

template <class HeapType>
class [[maybe_unused]] Heap {
public:
    [[maybe_unused]] Heap(HeapType *,int32_t);
    [[maybe_unused]] explicit Heap(int32_t);
    ~Heap();

    [[maybe_unused]] void heapify();

    [[maybe_unused]] void insert(HeapType key);
    [[maybe_unused]] HeapType remove(int32_t pos=0);

    [[maybe_unused]] void sort();
private:
    void fixHeap(int32_t root);

    HeapType
        *data;
    int32_t
        nElements,
        capacity;
};

#include "heap-implementation.h"
