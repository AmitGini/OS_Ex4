/*
No need to run make graph before running the following tests checks

Coverage Target: coverage: Adds COVFLAGS for code coverage, runs the executable, and generates gcov reports.
Using lcov to generate html with easy gui code coverage
make coverage  // it run the gcov and after that lcov for easy gui code coverage


Profiling Target: profile: Adds PROFFLAGS for profiling, runs the executable, and generates a gprof report.
make profile

Valgrind Memory Check Target: valgrind: Adds DEBUGFLAGS for debugging symbols, runs Valgrind with memory check.
make valgrind

Valgrind Call Graph Target:
callgrind: Adds DEBUGFLAGS for debugging symbols, runs Valgrind with Callgrind tool, and generates a callgrind report.
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
