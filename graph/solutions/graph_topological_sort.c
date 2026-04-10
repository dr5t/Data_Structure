#include <stdio.h>
#include <stdlib.h>

/**
 * QUESTION: Topological Sorting of a Directed Acyclic Graph (DAG).
 * 
 * ALGORITHM:
 * 1. For each node, if not visited, call DFS-Topological function.
 * 2. In DFS:
 *    a. Mark node as visited.
 *    b. Recurse for all adjacent nodes.
 *    c. After all neighbors are done, push current node to stack.
 * 3. Pop all elements from stack to get topological order.
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
}

// Stack Implementation for Topological Sort
int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void topoDFS(int v, int visited[], struct Graph* g) {
    visited[v] = 1;

    struct Node* temp = g->adjLists[v];
    while (temp) {
        if (!visited[temp->dest])
            topoDFS(temp->dest, visited, g);
        temp = temp->next;
    }

    push(v); // Push to stack after visiting all neighbors
}

void topologicalSort(struct Graph* g) {
    int visited[g->numV];
    for (int i = 0; i < g->numV; i++) visited[i] = 0;

    for (int i = 0; i < g->numV; i++) {
        if (!visited[i])
            topoDFS(i, visited, g);
    }

    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int V = 6;
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = V;
    g->adjLists = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) g->adjLists[i] = NULL;

    addEdge(g, 5, 2);
    addEdge(g, 5, 0);
    addEdge(g, 4, 0);
    addEdge(g, 4, 1);
    addEdge(g, 2, 3);
    addEdge(g, 3, 1);

    topologicalSort(g);

    return 0;
}
