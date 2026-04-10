#include <stdio.h>
#include <stdlib.h>

/**
 * QUESTION: Count the Number of Connected Components in an Undirected Graph.
 * 
 * ALGORITHM:
 * 1. Initialize all nodes as not visited.
 * 2. For each node, if not visited:
 *    a. Increment component count.
 *    b. Perform DFS/BFS from this node to mark all reachable nodes.
 * 3. Return the component count.
 */

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int numV;
    struct Node** adjLists;
};

struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* g, int s, int d) {
    struct Node* newNode = createNode(d);
    newNode->next = g->adjLists[s];
    g->adjLists[s] = newNode;

    newNode = createNode(s);
    newNode->next = g->adjLists[d];
    g->adjLists[d] = newNode;
}

void dfs(int v, int visited[], struct Graph* g) {
    visited[v] = 1;
    struct Node* temp = g->adjLists[v];
    while (temp) {
        if (!visited[temp->dest])
            dfs(temp->dest, visited, g);
        temp = temp->next;
    }
}

int countComponents(struct Graph* g) {
    int visited[g->numV];
    for (int i = 0; i < g->numV; i++) visited[i] = 0;

    int count = 0;
    for (int i = 0; i < g->numV; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, visited, g);
        }
    }
    return count;
}

int main() {
    int V = 6;
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = V;
    g->adjLists = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) g->adjLists[i] = NULL;

    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    // 0, 1, 2 is one component
    
    addEdge(g, 3, 4);
    // 3, 4 is another
    
    // 5 is an isolated component

    printf("Number of Connected Components: %d\n", countComponents(g));

    return 0;
}
