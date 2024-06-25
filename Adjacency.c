#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to create the adjacency matrix
void createGraph(int adjMatrix[MAX][MAX], int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0; // Initialize all elements to 0
        }
    }

    int edges, src, dest;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            printf("Invalid edge!\n");
            i--;
        } else {
            adjMatrix[src][dest] = 1; // For an undirected graph, also add adjMatrix[dest][src] = 1
        }
    }
}

// Function to display the adjacency matrix
void displayGraph(int adjMatrix[MAX][MAX], int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[MAX][MAX];
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    if (numVertices > MAX) {
        printf("Number of vertices exceeds the maximum limit of %d\n", MAX); 
        return 1;
    }

    createGraph(adjMatrix, numVertices);
    printf("The adjacency matrix is:\n");
    displayGraph(adjMatrix, numVertices);

    return 0;
}
