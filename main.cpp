#include <iostream>
#include "graph.h"

int main() {
    Graph g(5);
    g.addEdge(0, 1, 6);      // Add edge 0 - 1 with weight 6
    g.addEdge(0, 2, 3);      // Add edge 0 - 2 with weight 3
    g.addEdge(1, 2, 2);      // Add edge 1 - 2 with weight 2
    g.addEdge(1, 3, 5);      // Add edge 1 - 3 with weight 5
    g.addEdge(2, 4, 4);      // Add edge 2 - 4 with weight 4
    g.addEdge(3, 4, 7);      // Add edge 3 - 4 with weight 7
    // g.printMatrix();
    g.primMST();

    return 0;
}