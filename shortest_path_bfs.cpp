#include <iostream>
#include <queue>
using namespace std;

int* shortestPath(Graph* G,int source)
{
    bool* visited = (bool*) malloc(sizeof(bool) * G->V);
    int* parent = (int*) malloc(sizeof(int) * G->V);
    int* distance = (int*) malloc(sizeof(int) * G->V);

    for(int i = 0; i < G->V;i++)
    {
        visited[i] = false;
        parent[i] = -1;
        distance[i] = -1;
    }

    distance[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int e = q.front();
        q.pop();
        visited[e] =  true;
        for(int i = 0; i < G->V;i++)
            if(G->Adj[e][i] && !visited[i])
            {
                distance[i] = distance[e] + 1;
                q.push(i);
            }
    }
    return distance;
}
