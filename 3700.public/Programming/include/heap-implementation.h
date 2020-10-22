//
// Created by bob on 11/14/19.
//

#pragma once

#include <cstdint>
#include <stdexcept>
#include "heap.h"

#define HEAP_LAST_INTERNAL_NODE (nElements/2-1)
//#define IS_LEAF(n) ((n)>=nElements/2)
#define HEAP_LEFT_NODE(p) (2*(p)+1)
//#define HEAP_RIGHT_NODE(p) (2*(p)+2)
#define HEAP_PARENT_NODE(c) (((c)-1)/2)

template <typename HeapType>
[[maybe_unused]] Heap<HeapType>::Heap(HeapType *d,int32_t n) {

    data = d;
    nElements = n;

    capacity = 0;

    heapify();
}

template <typename HeapType>
[[maybe_unused]] Heap<HeapType>::Heap(int32_t c) {

    data = new HeapType[c];
    nElements = 0;

    capacity = c;
}

template <typename HeapType>
Heap<HeapType>::~Heap() {

    if (capacity > 0)
        delete[] data;
}

template <typename HeapType>
void Heap<HeapType>::heapify() {

    for (int32_t i=HEAP_LAST_INTERNAL_NODE;i>=0;i--)
        fixHeap(i);
}

template <typename HeapType>
[[maybe_unused]] void Heap<HeapType>::insert(HeapType key) {
    int32_t
        c,p;

    if (nElements == capacity)
        throw std::overflow_error("Heap is full");

    c = nElements;
    nElements++;

    while (c > 0) {
        p = HEAP_PARENT_NODE(c);
        if (data[p] > key)
            break;
        data[c] = data[p];
        c = p;
    }

    data[c] = key;
}

template <typename HeapType>
HeapType Heap<HeapType>::remove(int32_t pos) {
    HeapType
        tmp;

    if (pos < 0 || pos >= nElements)
        throw std::out_of_range("Illegal index ");

    tmp = data[pos];
    nElements--;
    data[pos] = data[nElements];
    fixHeap(pos);

    return tmp;
}

template <typename HeapType>
[[maybe_unused]] void Heap<HeapType>::sort() {

    for (int32_t i=nElements-1;i>0;i--)
        data[i] = remove();
}

template <typename HeapType>
void Heap<HeapType>::fixHeap(int32_t root) {
    HeapType
        tmp;
    int32_t
        c;

    tmp = data[root];

    while (root <= HEAP_LAST_INTERNAL_NODE) {
        c = HEAP_LEFT_NODE(root);
        if (c < nElements-1 && data[c+1] > data[c])
            c++;
        if (data[c] < tmp)
            break;

        data[root] = data[c];

        root = c;
    }

    data[root] = tmp;
}
