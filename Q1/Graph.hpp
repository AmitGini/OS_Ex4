#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

// Undirect Graph class
class Graph
{
private:
    int vertices;  // Number of vertices
    std::vector<std::vector<int>> adjMatrix;  // Adjacency matrix


public:
    Graph(int vertices);  // Constructor
    void addEdge(int u, int v);  // Add edge to the undirected graph
};

#endif
