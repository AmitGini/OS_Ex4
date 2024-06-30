#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph
{
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;
    
    void DFS(int v, std::vector<bool> &visited);

public:
    Graph(int vertices);
    void addEdge(int u, int v);
    bool isEulerian();
    void printEulerianCycle();
};

#endif
