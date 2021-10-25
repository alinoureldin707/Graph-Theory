#include <iostream>
#include <vector>
#include "distance.cpp"
using namespace std;


int eccentricity(Graph* G,int index)
{
    int *distance = shortestPath(G,index);
    int eccentricity = 0;
    for(int i = 0; i < G->V;i++)
        if(distance[i] > eccentricity) eccentricity = distance[i];
    return eccentricity;
}

vector<int> eccentricVertices(Graph* G,int index)
{
    int *distance = shortestPath(G,index);
    vector<int> vertices;
    int eccentricity = 0;
    for(int i = 0; i < G->V;i++)
        if(distance[i] > eccentricity) eccentricity = distance[i];
    for(int i = 0; i < G->V;i++)
        if(distance[i] == eccentricity) vertices.push_back(i);
    return vertices;
}