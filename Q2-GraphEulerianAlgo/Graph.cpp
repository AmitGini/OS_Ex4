#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// Constructor - initialize the number of vertices and the values in adjacency matrix to 0 (representing no edge)
Graph::Graph(int vertices) : vertices(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

// Add edge to the undirected graph.
void Graph::addEdge(int u, int v)
{
    // Check if the vertices are valid
    if(u == v || u >= vertices || v >= vertices || u < 0 || v < 0) {
        std::cout<<u<<", "<<v<<" are Invalid Vertices"<<std::endl;
        return;
    }
    adjMatrix[u][v] = 1;  // add edge
    adjMatrix[v][u] = 1;  // add edge (undirected graph)
    std::cout<<"Undirect Edges has been added ("<<u<<","<<v<<"), ("<<v<<","<<u<<")."<<std::endl;
}

// Depth First Search (DFS) algorithm for checking Eulerian graph
void Graph::DFS(int v, std::vector<bool> &visited)
{
    visited[v] = true;
    for (int i = 0; i < vertices; i++)
    {
        if (adjMatrix[v][i] && !visited[i])
        {
            DFS(i, visited);
        }
    }
}

// Check condition for Eulerian graph
bool Graph::isEulerian()
{
    std::vector<bool> visited(vertices, false);
    DFS(0, visited);

    // Check connectivity of the graph using DFS
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            std::cout<<"Graph is Not Connected therefore: ";
            return false;
        }
    }

    // Check if all vertices have even degree
    for (int i = 0; i < vertices; i++) {
        int degree = 0;
        for (int j = 0; j < vertices; j++) {
            degree += adjMatrix[i][j];
        }
        if (degree % 2 != 0) {
            std::cout<<"Found Odd Degree therefore: ";
            return false;
        }
    }

    return true;
}

// Algorithm to find Eulerian Cycle
/**
 * @brief Finds and prints the Eulerian Cycle of the graph if it exists.
 * 
 * This function first checks if the graph is Eulerian using the isEulerian() method.
 * If the graph is not Eulerian, it prints a message and returns.
 * Otherwise, it proceeds to find the Eulerian Cycle using a stack-based approach.
 * 
 * The algorithm works as follows:
 * 1. Make a copy of the adjacency matrix.
 * 2. Initialize a stack to store the current path and a vector to store the Eulerian Circuit.
 * 3. Start from vertex 0 and push it onto the stack.
 * 4. While the stack is not empty:
 *    - If the current vertex has no more edges, add it to the circuit and backtrack.
 *    - Otherwise, push the current vertex onto the stack, find the next vertex to visit, 
 *      remove the edge between the current vertex and the next vertex, and move to the next vertex.
 * 5. Print the Eulerian Circuit in reverse order.
 * 
 * @note This function assumes that the graph is represented as an adjacency matrix.
 */
void Graph::eulerianCycle()
{
    if (!isEulerian())  // Check if the graph answer the Eulerian conditions
    {
        std::cout << "Graph is not Eulerian\n";
        return;
    }

    std::vector<std::vector<int>> tempMatrix = adjMatrix;  // Make a copy of the adjacency matrix
    std::stack<int> curr_path;  // Stack to store the current path
    std::vector<int> circuit;  // Vector to store the Eulerian Circuit

    curr_path.push(0);  // Start from vertex 0
    int curr_v = 0;  // Current vertex

   // While the stack is not empty:
   //  - If the current vertex has no more edges, add it to the circuit and backtrack.
   //  - Otherwise, push the current vertex onto the stack, find the next vertex to visit, 
   //    remove the edge between the current vertex and the next vertex, and move to the next vertex.
    while (!curr_path.empty())
    {
        
        if (std::all_of(tempMatrix[curr_v].begin(), tempMatrix[curr_v].end(), [](int i){ return i == 0; }))
        {
            circuit.push_back(curr_v);
            curr_v = curr_path.top();
            curr_path.pop();
        }
        else
        {
            curr_path.push(curr_v);
            for (int next_v = 0; next_v < vertices; next_v++)
            {
                if (tempMatrix[curr_v][next_v])
                {
                    tempMatrix[curr_v][next_v] = 0;
                    tempMatrix[next_v][curr_v] = 0; // Remove the edge in both directions
                    curr_v = next_v;
                    break;
                }
            }
        }
    }

    // Print the Eulerian Circuit in reverse order.
    for (int i = circuit.size() - 1; i >= 0; i--)
    {
        std::cout << circuit[i];
        if (i > 0)
        {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}