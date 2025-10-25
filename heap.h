//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    //inserts index at end of heap, restores order using upheap()
    void push(int idx, int weightArr[]) {
        data[size] = idx;
        size++;
        upheap(size-1, weightArr);
    }

    //removes and returns the smallest index
    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            return -1; //empty heap
        }
        int idx = data[0];
        data[0] = data[size-1];
        size--;
        if (size > 0) {
            downheap(0, weightArr);
        }
        return idx;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif