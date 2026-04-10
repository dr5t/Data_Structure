#include <stdio.h>

/* 
 * QUESTION: Graph Adjacency Matrix
 * Represent a graph using a 2D array.
 */

#define V 4 // Number of vertices

void addEdge(int adj[V][V], int i, int j) {
    adj[i][j] = 1;
    adj[j][i] = 1; // For undirected graph
}

void display(int adj[V][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adj[V][V] = {0}; // Initialize all to 0

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    display(adj);

    return 0;
}
