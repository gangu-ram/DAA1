#include <stdio.h>
#include <stdbool.h>

#define V 5   

 
void classifyNodes(int graph[V][V]) {
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    printf("Live Nodes: ");
    for (int i = 0; i < V; i++) {
        if (graph[i][i] == 1) {
            printf("%d ", i);
            visited[i] = true;
        }
    }
    printf("\n");

    printf("E-Nodes: ");
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool eNode = true;
            for (int j = 0; j < V; j++) {
                if (graph[i][j] == 1 || graph[j][i] == 1) {
                    eNode = false;
                    break;
                }
            }
            if (eNode) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");

    printf("Dead Nodes: ");
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool deadNode = true;
            for (int j = 0; j < V; j++) {
                if (graph[i][j] == 1 || graph[j][i] == 1) {
                    deadNode = false;
                    break;
                }
            }
            if (deadNode) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

int main() {
    // Sample graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    classifyNodes(graph);

    return 0;
}
