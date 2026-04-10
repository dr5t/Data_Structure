#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * QUESTION: Graph BFS Traversal
 * Level-order traversal of a graph using a queue.
 */

#define MAX 10

struct Graph {
    int numV;
    int adj[MAX][MAX];
};

void bfs(struct Graph* g, int startNode) {
    bool visited[MAX] = {false};
    int queue[MAX], front = 0, rear = 0;

    visited[startNode] = true;
    queue[rear++] = startNode;

    printf("BFS Traversal: ");
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < g->numV; i++) {
            if (g->adj[curr][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph g = {4, {{0,1,1,0}, {1,0,1,0}, {1,1,0,1}, {0,0,1,0}}};
    bfs(&g, 0);
    return 0;
}
