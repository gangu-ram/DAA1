#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 6 // Number of vertices

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Create a queue for BFS
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if queue is full
bool isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Enqueue an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Depth First Search (DFS) traversal
void DFS(int graph[V][V], int start, bool visited[]) {
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < V; i++) {
        if (graph[start][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Breadth First Search (BFS) traversal
void BFS(int graph[V][V], int start) {
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    struct Queue* queue = createQueue(V);
    visited[start] = true;
    enqueue(queue, start);

    printf("Breadth First Traversal starting from vertex %d: ", start);

    while (!isEmpty(queue)) {
        int vertex = dequeue(queue);
        printf("%d ", vertex);

        for (int i = 0; i < V; i++) {
            if (graph[vertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }

    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    int start_vertex;
    printf("Enter the starting vertex for DFS and BFS: ");
    scanf("%d", &start_vertex);

    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    printf("Depth First Traversal starting from vertex %d: ", start_vertex);
    DFS(graph, start_vertex, visited);
    printf("\n");

    BFS(graph, start_vertex);

    return 0;
}
