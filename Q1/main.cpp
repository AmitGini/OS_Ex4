#include "Graph.hpp"
#include <iostream>

int main()
{
    int vertices = 5;
    Graph g(vertices);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    return 0;
}
