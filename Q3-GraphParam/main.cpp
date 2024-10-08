#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include "Graph.hpp"

// Function to print usage incase of invalid arguments
void usage() {
    std::cerr << "Usage: -v <vertices> -e <edges> -s <seed>" << std::endl;
}

int main(int argc, char *argv[])
{
    // Variables to store command line arguments
    int vertices = 0;
    int edges = 0;
    int argSeed = 0;
    
    // Parse command line arguments
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
    }catch(std::exception &e){ // Check if all arguments are provided
        usage();
        return EXIT_FAILURE;
    }

    // Check if all arguments are provided
    if (vertices <= 0 || edges <= 0 || argSeed < 0) {
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
        graph.addEdge(u, v);
    }

    std::cout << "Checking for Eulerian Cycle..." << std::endl;
    graph.eulerianCycle();

    return 0;
}
