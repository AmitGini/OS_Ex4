#include "Graph.hpp"
#include <iostream>

// Example of using the Graph class and its methods
int main()
{
    int vertices = 5;
    Graph g(vertices);
    g.addEdge(0, 0);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(0, -1);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(5, 2);

    return 0;
}
