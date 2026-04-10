#include <stdio.h>
#include <stdbool.h>

/* 
 * QUESTION: Graph DFS Traversal
 * Depth-first traversal of a graph using recursion.
 */

#define MAX 10

void dfsUtil(int adj[MAX][MAX], int v, int numV, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < numV; i++) {
        if (adj[v][i] && !visited[i]) {
            dfsUtil(adj, i, numV, visited);
        }
    }
}

void dfs(int adj[MAX][MAX], int numV, int startNode) {
    bool visited[MAX] = {false};
    printf("DFS Traversal: ");
    dfsUtil(adj, startNode, numV, visited);
    printf("\n");
}

int main() {
    int numV = 4;
    int adj[MAX][MAX] = {{0,1,1,0}, {1,0,1,0}, {1,1,0,1}, {0,0,1,0}};
    dfs(adj, numV, 0);
    return 0;
}
