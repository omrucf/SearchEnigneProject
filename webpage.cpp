#include "webpage.h"

sites::sites(vector<edge> const &edges, int n)
{
    adjList.resize(n);

    for (auto &edge : edges)
    {
        adjList[edge.loc].push_back(edge.dst);
    }
}

// void sites::CreateGraph(vector<edge> const &edges, int n)
// {
//     adjList.resize(n);

//     for (auto &edge : edges)
//     {
//         adjList[edge.loc].push_back(edge.dst);
//     }
// }
