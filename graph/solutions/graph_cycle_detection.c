#include <stdio.h>
#include <stdbool.h>

/* 
 * QUESTION: Graph Cycle Detection (Undirected)
 * Detect a cycle in an undirected graph using DFS.
 */

#define MAX 10

bool hasCycleUtil(int adj[MAX][MAX], int v, int numV, bool visited[], int parent) {
    visited[v] = true;

    for (int i = 0; i < numV; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (hasCycleUtil(adj, i, numV, visited, v)) return true;
            } else if (i != parent) {
                return true; // Cycle found
            }
        }
    }
    return false;
}

bool hasCycle(int adj[MAX][MAX], int numV) {
    bool visited[MAX] = {false};
    for (int i = 0; i < numV; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(adj, i, numV, visited, -1)) return true;
        }
    }
    return false;
}

int main() {
    int adj[MAX][MAX] = {{0,1,1,0}, {1,0,1,0}, {1,1,0,1}, {0,0,1,0}};
    if (hasCycle(adj, 4)) printf("Graph contains a cycle.\n");
    else printf("Graph does not contain a cycle.\n");
    return 0;
}
