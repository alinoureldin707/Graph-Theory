#include <iostream>
#include "Graph.cpp"
using namespace std;


void readGraph(Graph* G,bool isWeighted = false,bool isDirected = false)
{
    for(int i = 0; i < G->E;i++)
    {
        int u,v,w = 1;
        if(isWeighted) cin >> u >> v >> w;
        else cin >> u >> v;
        if(isDirected) G->Adj[u][v] = w;
        else G->Adj[u][v] = G->Adj[v][u] = w;
    }
}
