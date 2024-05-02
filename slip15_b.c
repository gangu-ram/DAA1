#include <stdio.h>
#include <stdbool.h>

#define V 4  

 
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

 
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;  
    }

 
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

 
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, then backtrack
            color[v] = 0;
        }
    }

    return false; // No color can be assigned to this vertex
}

// Function to print the solution
void printSolution(int color[]) {
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

// Function to color the graph using m colors
void graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all colors as 0 (unassigned)
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("No solution exists with %d colors.\n", m);
    } else {
        printSolution(color);
    }
}

int main() {
    // Sample graph represented as an adjacency matrix
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    printf("Graph Coloring with %d colors:\n", m);
    graphColoring(graph, m);

    return 0;
}
