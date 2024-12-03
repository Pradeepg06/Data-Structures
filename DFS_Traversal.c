#include <stdio.h>
#define MAX 10  // Maximum number of vertices

// Function to perform DFS
void dfs(int graph[MAX][MAX], int visited[MAX], int vertex, int vertices) {
    // Mark the current vertex as visited
    visited[vertex] = 1;

    // Visit all unvisited neighbors
    for (int i = 0; i < vertices; i++) 
    {
        if (graph[vertex][i] == 1 && !visited[i]) 
        {
            dfs(graph, visited, i, vertices);
        }
    }
}

// Main function
int main() 
{
    int graph[MAX][MAX], visited[MAX];
    int vertices, edges, i, j;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (Aij):\n");
    for (i = 0; i < vertices; i++) 
    {
        for (j = 0; j < vertices; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for (i = 0; i < vertices; i++) 
    {
        visited[i] = 0;
    }

    // Perform DFS starting from vertex 0
    dfs(graph, visited, 0, vertices);

    // Check if all vertices are visited
    int isConnected = 1;  // Assume the graph is connected
    for (i = 0; i < vertices; i++) 
    {
        if (visited[i] == 0) 
        {
            isConnected = 0;  // Found a vertex that is not reachable
            break;
        }
    }

    // Print the result
    if (isConnected) 
    {
        printf("\nThe graph is connected.\n");
    } 
    else 
    {
        printf("\nThe graph is not connected.\n");
    }

    return 0;
}