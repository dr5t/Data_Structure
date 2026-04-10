#include <stdio.h>
#include <stdlib.h>

/* 
 * QUESTION: Graph Adjacency List
 * Represent a graph using an array of linked lists.
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
    // Edge from s to d
    struct Node* newNode = createNode(d);
    newNode->next = g->adjLists[s];
    g->adjLists[s] = newNode;

    // Edge from d to s (Undirected)
    newNode = createNode(s);
    newNode->next = g->adjLists[d];
    g->adjLists[d] = newNode;
}

void printGraph(struct Graph* g) {
    for (int i = 0; i < g->numV; i++) {
        struct Node* temp = g->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V_count = 4;
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numV = V_count;
    g->adjLists = malloc(V_count * sizeof(struct Node*));

    for (int i = 0; i < V_count; i++) g->adjLists[i] = NULL;

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);

    printGraph(g);

    return 0;
}
