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

    //swaps child upward while smaller than parent
    void upheap(int pos, int weightArr[]) {
        int parent = (pos - 1) / 2;
        while (pos > 0 && (weightArr[data[pos]] < weightArr[data[parent]])) {
            swap(data[pos], data[parent]);
            pos = parent;
            parent = (pos - 1) / 2;
        }
    }

    //swaps parent downward while larger than any child
    void downheap(int pos, int weightArr[]) {
        int leftChild = 2 * pos + 1;
        int rightChild = 2 * pos + 2;
        int smallest = pos;

        if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) {
            smallest = leftChild;
        }
        if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) {
            smallest = rightChild;
        }

        if (smallest != pos) {
            swap(data[pos], data[smallest]);
            downheap(smallest, weightArr); // recursive call
        }
    }
};

#endif