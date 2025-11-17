#include <stdio.h>

int adj[10][10];     // adjacency matrix
int visited[10];     // for DFS
int queue[20];       // for BFS
int front = -1, rear = -1;

void dfs(int v, int n) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

void bfs(int start, int n) {
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);
        
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;        
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // DFS
    for (int i = 1; i <= n; i++) visited[i] = 0;
    printf("\nDFS Traversal: ");
    dfs(start, n);

    // BFS
    for (int i = 1; i <= n; i++) visited[i] = 0;
    printf("\nBFS Traversal: ");
    bfs(start, n);

    printf("\n");
    return 0;
}
