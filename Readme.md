[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Matthew Tabios

## Description
Briefly describe what your program does and how the code is structured.
- This program implement's Prim Algorithm through the use of a priority queue and an adjacency matrix
## Files
- graph.h / graph.cpp
  - creates the adjacency matrix based off edges given
- heap.h / heap.cpp
  - implements the priority queue function
- main.cpp (unchanged)
  - implements functions
- README.md
  - describes what the program is

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | o(logv)         |
| Extract Min          | o(logv)         |
| Decrease Key         | o(logv)         |
| Prim’s MST Overall   | 0((V + E)logv)  |

_Explain why your MST implementation has the above runtime._
- Insert in MinHeap
  - Worst case, the inserted element has to bubble up to the root, hence a time complexity of o(log(v))
- Extract Min
  - worst case, the element to replace the root has to bubble all the way back down to the bottom of the tree, hence a 
    time complexity of o(logv)
- Decrease Key
  - Worse case, the updated key value has to move all the way up to the root
- Prim's MST overall
    - Extract Min has to happen V times
    - Decrease Key has to run at least E times
    - hence o((v + e)logv)
## Test Case Description

Input: 

    Graph g(5);
    g.addEdge(0, 1, 6);      // Add edge 0 - 1 with weight 6
    g.addEdge(0, 2, 3);      // Add edge 0 - 2 with weight 3
    g.addEdge(1, 2, 2);      // Add edge 1 - 2 with weight 2
    g.addEdge(1, 3, 5);      // Add edge 1 - 3 with weight 5
    g.addEdge(2, 4, 4);      // Add edge 2 - 4 with weight 4
    g.addEdge(3, 4, 7);      

Output:
2 - 1 (2)
0 - 2 (3)
1 - 3 (5)
2 - 4 (4)
Total weight of MST: 14