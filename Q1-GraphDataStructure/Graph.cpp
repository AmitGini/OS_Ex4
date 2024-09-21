#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// Constructor - initialize the number of vertices and the values in adjacency matrix to 0 (representing no edge)
Graph::Graph(int vertices) : vertices(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

// Add edge to the undirected graph, if the vertices are valid.
void Graph::addEdge(int u, int v)
{
    // Check if the vertices are valid
    if(u == v || u >= vertices || v >= vertices || u < 0 || v < 0) {
        std::cout<<u<<", "<<v<<" are Invalid Vertices"<<std::endl;
        return;
    }
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
    std::cout<<"Undirect Edges has been added ("<<u<<","<<v<<"), ("<<v<<","<<u<<")."<<std::endl;
}

