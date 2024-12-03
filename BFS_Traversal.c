#include <stdio.h>
#define MAX 10  // Maximum number of vertices

// Function to perform BFS traversal
void bfs(int graph[MAX][MAX], int visited[MAX], int start, int vertices) {
    int queue[MAX], front = -1, rear = -1;

    // Enqueue the starting vertex and mark it as visited
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        // Dequeue a vertex
        int current = queue[++front];
        printf("%d ", current);

        // Visit all unvisited neighbors of the current vertex
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Main function
int main() {
    int graph[MAX][MAX], visited[MAX];
    int vertices, i, j, start;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Input the adjacency matrix
    printf("Enter the Adjacency matrix (Aij) that represents Graph: \n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the visited array
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    // Input the starting vertex for BFS
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Perform BFS
    bfs(graph, visited, start, vertices);

    return 0;
}