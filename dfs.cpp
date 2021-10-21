#include <iostream>
using namespace std;


void dfsTraversal(Graph* G,int index,bool* visited)
{
    cout << index << " "; // deal with node
    visited[index] = true; // set the parent node as visited
    for(int i = 0; i < G->V;i++) // loop over its children
        if(G->Adj[index][i] != 0 && !visited[i])
            dfsTraversal(G,i,visited);
}

void dfs(Graph* G)
{
    bool* visited = (bool*) malloc(sizeof(bool) * G->V); // create a visited list
    for(int i = 0; i < G->V;i++) // initialize all nodes as not visited(false)
        visited[i] = false;
    for(int i = 0; i < G->V;i++)
        if(!visited[i])
            dfsTraversal(G,i,visited);
}
