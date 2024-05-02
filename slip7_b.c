#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

 
struct Graph {
    int V; // Number of vertices
    int **adjMatrix; // Adjacency matrix
};

// Function to create a new graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            graph->adjMatrix[i][j] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

// Depth First Search (DFS) function to perform topological sorting
void topologicalSortUtil(struct Graph* graph, int v, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1;

    // Visit all adjacent vertices of the current vertex
    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[v][i] && !visited[i])
            topologicalSortUtil(graph, i, visited, stack, stackIndex);
    }

    // Push current vertex to stack
    stack[++(*stackIndex)] = v;
}

// Function to perform topological sorting
void topologicalSort(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
    int stack[MAX_VERTICES]; // Stack to store topologically sorted vertices
    int stackIndex = -1;

    // Perform DFS for each vertex if not visited
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
    }

    // Print vertices in topologically sorted order (pop from stack)
    printf("Topological Sorting: ");
    while (stackIndex >= 0) {
        printf("%d ", stack[stackIndex--]);
    }
}

int main() {
    // Create a graph
    struct Graph* graph = createGraph(6);

    // Add edges
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    // Perform topological sorting
    topologicalSort(graph);

    return 0;
}
