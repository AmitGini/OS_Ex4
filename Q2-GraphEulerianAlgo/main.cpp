#include "Graph.hpp"
#include <iostream>

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

    // Adding another graph with an Eulerian cycle
    Graph h(vertices);
    h.addEdge(0, 1);
    h.addEdge(1, 2);
    h.addEdge(2, 3);
    h.addEdge(3, 4);
    h.addEdge(4, 0); // This completes the cycle, connecting back to the start

    g.eulerianCycle();
    h.eulerianCycle();    

    return 0;
}
