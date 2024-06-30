#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

Graph::Graph(int vertices) : vertices(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

void Graph::addEdge(int u, int v)
{
    if(u == v || u >= vertices || v >= vertices || u < 0 || v < 0) return;
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}

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


// void Graph::printEulerianCycle()
// {
//     if (!isEulerian())
//     {
//         std::cout << "Graph is not Eulerian\n";
//         return;
//     }
//     std::stack<int> curr_path;
//     std::vector<int> circuit;
//     curr_path.push(0);
//     int curr_v = 0;
//     while (!curr_path.empty())
//     {
//         if (adjMatrix[curr_v].empty())
//         {
//             circuit.push_back(curr_v);
//             curr_v = curr_path.top();
//             curr_path.pop();
//         }
//         else
//         {
//             curr_path.push(curr_v);
//             int next_v = adjMatrix[curr_v].back();
//             adjMatrix[curr_v].pop_back();
//             auto it = std::find(adjMatrix[next_v].begin(), adjMatrix[next_v].end(), curr_v);
//             if (it != adjMatrix[next_v].end()) {
//                 adjMatrix[next_v].erase(it);
//             }
//             curr_v = next_v;
//         }
//     }
//     for (int i = circuit.size() - 1; i >= 0; i--)
//     {
//         std::cout << circuit[i] << (i ? " -> " : "\n");
//     }
// }
void Graph::printEulerianCycle()
{
    if (!isEulerian())
    {
        std::cout << "Graph is not Eulerian\n";
        return;
    }

    std::vector<std::vector<int>> tempMatrix = adjMatrix; // Make a copy of the adjacency matrix
    std::stack<int> curr_path;
    std::vector<int> circuit;

    curr_path.push(0);
    int curr_v = 0;

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