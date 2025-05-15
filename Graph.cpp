//
// Created by Matthew Tabios on 5/10/25.
//
#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>
using namespace std;

Graph::Graph(int vertices) {
    numVertices = vertices;
    dne = INT_MAX;

    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j)
            adjMatrix[i][j] = (i == j) ? 0 : dne;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}


void Graph::primMST() {
    int* parent = new int[numVertices];
    int* key = new int[numVertices];
    MinHeap minHeap(numVertices);

    for (int v = 0; v < numVertices; ++v) {
        key[v] = INT_MAX;
        parent[v] = -1;
        minHeap.insert(v, key[v]);
    }

    key[0] = 0;
    minHeap.decreaseKey(0, 0);

    while (!minHeap.isEmpty()) {
        int currentVertex = minHeap.extractMin();

        for (int i = 0; i < numVertices; i++) {
            int weight = adjMatrix[currentVertex][i];
            if (weight != 0 && weight != dne && minHeap.isInMinHeap(i) && weight < key[i]) {
                key[i] = weight;
                parent[i] = currentVertex;
                minHeap.decreaseKey(i, weight);
            }
        }
    }

    // Print MST
    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << " (" << adjMatrix[i][parent[i]] << ")\n";
        totalWeight += adjMatrix[i][parent[i]];
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    delete[] parent;
    delete[] key;
}





