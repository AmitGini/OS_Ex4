#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph
{
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;


public:
    Graph(int vertices);
    void addEdge(int u, int v);

};

#endif
