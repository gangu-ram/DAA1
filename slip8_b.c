#include <stdio.h>
#include <limits.h>

#define V 4  

 
int minDistance(int dist[], int visited[]) 
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

 
void printPath(int parent[], int n, int graph[V][V]) 
{
    printf("Path: ");
    for (int i = 0; i < n; i++)
        printf("%d -> ", parent[i]);
    printf("0\n");

    printf("Distance: %d\n", graph[parent[n - 1]][0]);
}

 
void nearestNeighbor(int graph[V][V]) 
{
    int parent[V];  
    int visited[V] = {0};  
    int dist[V];  

 
    for (int i = 0; i < V; i++)
        parent[i] = -1, dist[i] = INT_MAX;

 
    visited[0] = 1;
    parent[0] = -1;
    dist[0] = 0;

 
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, visited); 
        visited[u] = 1;  

 
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < dist[v])
                parent[v] = u, dist[v] = graph[u][v];
    }

 
    printPath(parent, V, graph);
}

int main() 
{
 
    int graph[V][V] = 
    {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

 
    nearestNeighbor(graph);

    return 0;
}
