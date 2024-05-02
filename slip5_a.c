#include <stdio.h>
#include <stdlib.h>


struct Edge 
{
    int src, dest, weight;
};

struct Subset 
{
    int parent;
    int rank;
};

 
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
void kruskalMST(struct Edge* edges, int V, int E);

 
int find(struct Subset subsets[], int i) 
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

 
void Union(struct Subset subsets[], int x, int y) 
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int compareEdges(const void* a, const void* b) 
{
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

 
void kruskalMST(struct Edge* edges, int V, int E) 
{
 
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

 
    for (int v = 0; v < V; v++) 
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

 
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    struct Edge resultMST[V];  
    int e = 0;  

 
    int i = 0;

 
    while (e < V - 1 && i < E) 
    {
 
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

 
        if (x != y) 
        {
            resultMST[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

 
    printf("Edges of the Minimum Cost Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d\tWeight: %d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);

 
    free(subsets);
}

int main() 
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) 
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, V, E);

 
    free(edges);

    return 0;
}
