#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class node
{
    public:
        int data,distance;
        bool operator() (node a, node b)
        {
            return a.distance > b.distance;
        }
};

int* Dijstra(Graph* G,int source)
{
    int* parent = (int*) malloc(sizeof(int) * G->V);
    int* distance = (int*) malloc(sizeof(int) * G->V);

    for(int i = 0; i < G->V;i++) parent[i] = distance[i] = -1;
    distance[source] = 0;

    priority_queue<node,vector<node>,node> pq;
    pq.push({source,0});

    while(!pq.empty())
    {
        node e = pq.top();
        pq.pop();
        for(int i = 0; i < G->V;i++)
            if(G->Adj[e.data][i] != 0 && (distance[i] == -1 || distance[i] > G->Adj[e.data][i] + distance[e.data]))
            {
                distance[i] = G->Adj[e.data][i] + distance[e.data];
                parent[i] = e.data;
                pq.push({i,distance[i]});
            }
    }
    return distance;
}