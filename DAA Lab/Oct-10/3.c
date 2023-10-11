#include <stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int n, m;

void dfs(int v) {
    printf("%d -> ", v);
    visited[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges of the graph: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int startVertex;
    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);

    printf("The adjacency matrix is as follows:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("The DFS traversal from vertex %d is as follows: ", startVertex);
    dfs(startVertex);
    printf("\n");

    return 0;
}
