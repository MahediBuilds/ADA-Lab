#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX], stack[MAX], top = -1;
int n;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && !visited[v])
            dfs(v);
    }
    stack[++top] = u;
}

void topologicalSort() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    top = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }

    printf("Topological Order:\n");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v) where u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();
    return 0;
}
