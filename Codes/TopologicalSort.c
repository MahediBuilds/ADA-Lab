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

void topologicalSortSourceRemoval() {
    int in_degree[MAX];
    for (int i = 0; i < n; i++) {
        in_degree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (graph[j][i])
                in_degree[i]++;
        }
    }
    int count = 0;
    int tempGraph[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tempGraph[i][j] = graph[i][j];
    int printed[MAX] = {0};
    printf("Topological Order (Source Removal):\n");
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0 && !printed[i]) {
                printf("%d ", i);
                printed[i] = 1;
                count++;
                for (int j = 0; j < n; j++) {
                    if (tempGraph[i][j]) {
                        in_degree[j]--;
                        tempGraph[i][j] = 0;
                    }
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nCycle detected. Topological sort not possible.\n");
            return;
        }
    }
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
    topologicalSortSourceRemoval();
    return 0;
}

/*
Input:
Enter number of vertices: 6
Enter number of edges: 8
Enter edges (u v) where u -> v:
5 2
5 0
4 0
4 1
2 3
3 1
0 3
1 3

Output:
Topological Order:
5 4 2 0 1 3
Topological Order (Source Removal):
5 4 2 0 1 3
*/
