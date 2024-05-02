#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // Number of vertices

 
int graph[V][V] = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 0, 0, 1}
};

 
bool visited[V];

 
void DFS(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
 
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    printf("Depth First Search starting from vertex 0:\n");
    DFS(0);  

    return 0;
}
