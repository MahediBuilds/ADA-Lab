#include <stdio.h>
#include <limits.h>

#define V 5

void primMSTNoParent(int graph[V][V]) {
    int visited[V] = {0};
    int fromEdge[V - 1], toEdge[V - 1], edgeWeight[V - 1];
    int edgeCount = 0;
    visited[0] = 1;

    for(int i = 0; i < V - 1; i++) {
        int minWeight = INT_MAX;
        int fromVertex = -1;
        int toVertex = -1;
        for(int u = 0; u < V; u++) {
            if(visited[u] == 1) {
                for(int v = 0; v < V; v++) {
                    if(visited[v] == 0 && graph[u][v] != 0 && graph[u][v] < minWeight) {
                        minWeight = graph[u][v];
                        fromVertex = u;
                        toVertex = v;
                    }
                }
            }
        }
        fromEdge[edgeCount] = fromVertex;
        toEdge[edgeCount] = toVertex;
        edgeWeight[edgeCount] = minWeight;
        edgeCount++;
        visited[toVertex] = 1;
    }

    printf("Edge\tWeight\n");
    for(int i = 0; i < edgeCount; i++) {
        printf("%d - %d\t%d\n", fromEdge[i], toEdge[i], edgeWeight[i]);
    }
}

int main() {
    int graph[V][V];
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMSTNoParent(graph);
    return 0;
}