#include <iostream>
#include <vector>
#include "eccentricity.cpp"
using namespace std;


vector<int> periphery(Graph* G)
{
    vector<int> peripheries;
    vector<int> eccentricities;
    for(int i = 0; i < G->V;i++)
        eccentricities.push_back(eccentricity(i));
    int max = eccentricities[0];
    for(int i = 1; i < G->V;i++)
        if(eccentricities[i] > max) max = eccentricities[i];
    for(int i = 0; i < G->V;i++)
        if(eccentricities[i] == max) peripheries.push_back(i);
    return peripheries;
}