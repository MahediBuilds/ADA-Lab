#include <stdio.h>

#define V 10
#define INF 9999

void floyd(int graph[V][V], int n) {
    int dist[V][V];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, graph[V][V];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 9999 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Edge (%d, %d): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    floyd(graph, n);

    return 0;
}

/* 

Sample Input:
Enter the number of vertices: 4
Enter the adjacency matrix (use 9999 for infinity):
Edge (0, 0): 0
Edge (0, 1): 5
Edge (0, 2): 9999
Edge (0, 3): 10
Edge (1, 0): 9999
Edge (1, 1): 0
Edge (1, 2): 3
Edge (1, 3): 9999
Edge (2, 0): 9999
Edge (2, 1): 9999
Edge (2, 2): 0
Edge (2, 3): 1
Edge (3, 0): 9999
Edge (3, 1): 9999
Edge (3, 2): 9999
Edge (3, 3): 0

Expected Output:
Shortest distances between every pair of vertices:
0       5       8       9
9999    0       3       4
9999    9999    0       1
9999    9999    9999    0

*/
