#include <iostream>

using namespace std;

class Graph{
    public:
        int V,E;
        int** Adj;
    Graph(int V,int E)
    {
        this->V = V;
        this->E = E;
        this->Adj = (int**) malloc(sizeof(int*) * this->V);
        for(int i = 0; i < this->V;i++)
        {
            this->Adj[i] = (int*) malloc(sizeof(int) * this->V);
            for(int j = 0; j < this->V;j++)
                this->Adj[i][j] = 0;
        }
    }
    
};

