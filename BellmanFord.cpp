#include <iostream>
#include <queue>
#include <limits>

using namespace std;

int* BellmanFord(Graph* G,int source)
{
    int* distance = (int*) malloc(sizeof(int) * G->V);
    int* parent = (int*) malloc(sizeof(int) * G->V);
    bool* inQueue = (bool*) malloc(sizeof(bool) * G->V);

    for(int i = 0; i < G->V;i++)
    {
        distance[i] = numeric_limits<int>::max();
        parent[i] = -1;
        inQueue[i] = false;
    }

    queue<int> q;
    q.push(source);
    distance[source] = 0;
    inQueue[source] = true;

    while(!q.empty())
    {
        int e = q.front();
        q.pop();
        inQueue[e] = false;
        
        for(int i = 0; i < G->V;i++)
            if(G->Adj[e][i] != 0 && distance[i] > G->Adj[e][i] + distance[e])
            {
                distance[i] = G->Adj[e][i] + distance[e];
                parent[i] = e;
                inQueue[i] = true;
                q.push(i);
            }
    }
}