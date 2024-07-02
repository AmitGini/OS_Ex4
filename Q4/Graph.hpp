#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph
{
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;
    bool isEulerian();
    void DFS(int v, std::vector<bool> &visited);

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int u, int v);
    void printEulerianCycle();
};

#endif
