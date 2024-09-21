/*
No need to run make graph before running the following tests checks

Coverage Target - 
    Runs the executable, and generates gcov reports represented in HTML intutive GUI.
make coverage


Profiling Target -
   Runs the executable, analyze the performance of the code, by checking the time taken by each function.
make profile

Memory Check Target - 
    Check memory leaks, using valgrind with memcheck tools.
make memcheck

Note! it wont show static buffer overflow (for example array of 10 and trying to access 11th element)

Callgrind Target -
    callgrind: runs the executuble and analyze the use to detect insufficiency in the code.
make callgrind
*/

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include "Graph.hpp"

void usage() {
    std::cerr << "Usage: -v <vertices> -e <edges> -s <seed>" << std::endl;
}

int main(int argc, char *argv[])
{
    int vertices = 0;
    int edges = 0;
    int argSeed = 0;
    
    int opt;
    try{
        while ((opt = getopt(argc, argv, "v:e:s:")) != -1) {
            switch (opt) {
                case 'v':
                    vertices = std::stoi(optarg);
                    break;
                case 'e':
                    edges = std::stoi(optarg);
                    break;
                case 's':
                    argSeed = std::stoi(optarg);
                    break;
                default:
                    usage();
                    return EXIT_FAILURE;
            }
        }
    }catch(std::exception &e){
        usage();
        return EXIT_FAILURE;
    }

    if (vertices <= 0 || edges <= 0 || argSeed <= 0) {
        usage();
        return EXIT_FAILURE;
    }

    int seedTime = static_cast<int>(std::time(0)); // Use current time
    int seed = argSeed + seedTime; // Combine seed from argument and current time
    std::mt19937 rng(seed); // Mersenne Twister random number generator
    std::uniform_int_distribution<int> vertex_dist(0, vertices - 1);

    Graph graph(vertices);

    // Adding random edges
    for (int i = 0; i < edges; ++i) {
        int u = vertex_dist(rng);
        int v = vertex_dist(rng);
        std::cout<<"("<<u<<", "<<v<<")"<<std::endl;
        graph.addEdge(u, v);
    }

    std::cout << "Checking for Eulerian Cycle..." << std::endl;
    graph.eulerianCycle();

    // Graph case odd degree
    int verOddDegree = 4;
    Graph oddDegree(verOddDegree);
    oddDegree.addEdge(0, 1);
    oddDegree.addEdge(0, 2);
    oddDegree.addEdge(0, 3);
    oddDegree.eulerianCycle();

    // Graph case, unconnected
    int verUnconnected = 3;
    Graph unConnectedGraph(verUnconnected);
    unConnectedGraph.eulerianCycle();

    // Graph case found Eulerian cycle
    int verEulerGRaph = 5;
    Graph* eulerGraph = new Graph(verEulerGRaph);
    eulerGraph->addEdge(0, 1);
    eulerGraph->addEdge(1, 2);
    eulerGraph->addEdge(2, 3);
    eulerGraph->addEdge(3, 4);
    eulerGraph->addEdge(4, 0); // This completes the cycle, connecting back to the start
    eulerGraph->eulerianCycle(); 
    delete eulerGraph;


    return 0;
}
