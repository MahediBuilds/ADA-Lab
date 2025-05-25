#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int parent[], int u, int v) {
    int set_u = find(parent, u);
    int set_v = find(parent, v);
    parent[set_u] = set_v;
}

void kruskal(struct Edge edges[], int n, int e) {
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;
    printf("Edges in Minimum Cost Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(parent, u) != find(parent, v)) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            cost += edges[i].weight;
            unionSets(parent, u, v);
        }
    }
    printf("Total Minimum Cost = %d\n", cost);
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edges[e];
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    qsort(edges, e, sizeof(struct Edge), compare);
    kruskal(edges, n, e);

    return 0;
}
