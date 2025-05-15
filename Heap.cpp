//
// Created by Matthew Tabios on 5/10/25.
//
#include "heap.h"
#include <iostream>
#include "heap.h"
#include <iostream>
#include <climits>
using namespace std;

MinHeap::MinHeap(int c) {
    capacity = c;
    size = 0;
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];

    for (int i = 0; i < capacity; ++i) {
        position[i] = -1;  // Not in heap initially
        keyArray[i] = INT_MAX;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size && position[vertex] >= 0;
}

void MinHeap::insert(int vertex, int key) {
    if (size == capacity) {
        cout << "Heap overflow\n";
        return;
    }

    size++;
    int i = size - 1;
    heapArray[i] = vertex;
    keyArray[vertex] = key;
    position[vertex] = i;

    // Fix the min-heap property
    while (i != 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        position[heapArray[i]] = (i - 1) / 2;
        position[heapArray[(i - 1) / 2]] = i;
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[vertex] = newKey;

    while (i != 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        position[heapArray[i]] = (i - 1) / 2;
        position[heapArray[(i - 1) / 2]] = i;
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::minHeapify(int idx) {
    int min = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[min]])
        min = left;

    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[min]])
        min = right;

    if (min != idx) {
        int smallestVertex = heapArray[min];
        int idxVertex = heapArray[idx];

        // Update positions
        position[smallestVertex] = idx;
        position[idxVertex] = min;

        swap(heapArray[min], heapArray[idx]);
        minHeapify(min);
    }
}

int MinHeap::extractMin() {
    if (isEmpty()) {
        cout << "Heap underflow\n";
        return -1;
    }

    int root = heapArray[0];
    int last = heapArray[size - 1];
    heapArray[0] = last;

    position[root] = -1;
    position[last] = 0;
    size--;

    minHeapify(0);
    return root;
}









