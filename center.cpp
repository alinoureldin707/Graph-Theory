#include <iostream>
#include <vector>
#include "eccentricity.cpp"
using namespace std;


vector<int> center(Graph* G)
{
    vector<int> centers;
    vector<int> eccentricities;
    for(int i = 0; i < G->V;i++)
        eccentricities.push_back(eccentricity(i));
    int minEcc = eccentricities[0];
    for(int i = 1; i < G->V;i++)
        if(eccentricities[i] < min) min = eccentricities[i];
    for(int i = 0; i < G->V;i++)
        if(eccentricities[i] == min) centers.push_back(i);
    return centers;
}