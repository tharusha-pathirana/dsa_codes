
#include <iostream>
using namespace std;
#include <limits.h>
  

#define V 6
  

int minimumDistance(int dist[], bool sptSet[])
{
  
    
    int min = INT_MAX; 
    int min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}
  

void dijkstra(int graph[V][V], int sourceCity)
{
    int dist[V]; 
                
  
    bool sptSet[V]; 
                   
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
    
    dist[sourceCity] = 0;
  
    
    for (int count = 0; count < V - 1; count++) {
        
        int u = minimumDistance(dist, sptSet);
  
        
        sptSet[u] = true;
  
        
        for (int v = 0; v < V; v++)
  
            
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    
    printSolution(dist);
}
  

int main()
{
  
   
    int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0,0 } };
  
    
    dijkstra(graph, 5);
  
    return 0;
}
