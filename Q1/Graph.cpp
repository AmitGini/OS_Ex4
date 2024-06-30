#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

Graph::Graph(int vertices) : vertices(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

void Graph::addEdge(int u, int v)
{
    if(u == v || u >= vertices || v >= vertices || u < 0 || v < 0) return;
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}

