#include <stdio.h>

#define V 10

void warshall(int graph[V][V], int n) {
    int reach[V][V];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            reach[i][j] = graph[i][j];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printf("Transitive closure (reachability matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, graph[V][V];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("Edge (%d, %d): ", i, j);
            scanf("%d", &graph[i][j]);
        }

    warshall(graph, n);

    return 0;
}