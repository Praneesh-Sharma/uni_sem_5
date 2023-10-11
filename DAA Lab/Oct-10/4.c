#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int distances[MAX_NODES];
int n, m;
int startVertex;

typedef struct {
    int data[MAX_NODES];
    int front, rear;
} Queue;

Queue q;

void initQueue() {
    q.front = q.rear = -1;
}

bool isQueueEmpty() {
    return q.front == -1;
}

void enqueue(int node) {
    if (q.rear == MAX_NODES - 1) {
        printf("Queue is full\n");
    } else {
        if (q.front == -1) {
            q.front = 0;
        }
        q.rear++;
        q.data[q.rear] = node;
    }
}

int dequeue() {
    int node;
    if (isQueueEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        node = q.data[q.front];
        q.front++;
        if (q.front > q.rear) {
            q.front = q.rear = -1;
        }
        return node;
    }
}

void bfs(int startVertex) {
    initQueue();
    int i, currentNode;
    bool visited[MAX_NODES] = {false};

    enqueue(startVertex);
    visited[startVertex] = true;
    distances[startVertex] = 0;

    while (!isQueueEmpty()) {
        currentNode = dequeue();
        printf("%d->", currentNode);

        for (i = 1; i <= n; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                enqueue(i);
                visited[i] = true;
                distances[i] = distances[currentNode] + 2; // Edge weight is 2 units
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices and edges of the graph: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        distances[i] = -1;
        for (int j = 1; j <= n; j++) {
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

    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal: ");
    bfs(startVertex);
    printf("\n");

    printf("Distance: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", distances[i]);
    }
    printf("\n");

    return 0;
}
