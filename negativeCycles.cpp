#include <iostream>
#include <limits>

bool negativeCycle(Graph* G)
{
    int* distance = (int*) malloc(sizeof(int) * G->V);

    for(int i = 0; i < G->V;i++)
        distance[i] = numeric_limits<int>::max();
    distance[0] = 0;

    // loop over the bellmanFord algorithm V-1 times
    for(int v = 0; v < G->V - 1;v++)
    {
        for(int i = 0; i < G->V;i++)
            for(int j = 0; j < G->V;j++)
                if(G->Adj[i][j] != 0 && distance[j] > distance[i] + G->Adj[i][j])
                    distance[j] = distance[i] + G->Adj[i][j];
    }

    // run the algorithm again to check whether there exist negative cycles
    for(int v = 0; v < G->V - 1;v++)
    {
        for(int i = 0; i < G->V;i++)
            for(int j = 0; j < G->V;j++)
                if(G->Adj[i][j] != 0 && distance[j] > distance[i] + G->Adj[i][j])
                    return true;
    }

    return false;

}