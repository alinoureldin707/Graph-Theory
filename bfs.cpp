#include <iostream>
#include <queue>

using namespace std;

void bfs(Graph* G)
{
    bool* visited = (bool*) malloc(sizeof(bool) * G->V);
    for(int i = 0; i < G->V;i++) visited[i] = false; // declaring a visited list

    queue<int> q;
    q.push(0);
    while(!q.empty()) // visited all the children of the node before passing to the next node
    {
        int index = q.front();
        cout << index << " "; // deal with the node
        visited[index] = true;
        q.pop();
        for(int i = 0; i < G->V;i++)
            if(G->Adj[index][i] && !visited[i])
                q.push(i);
    }
}