#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * QUESTION: Dijkstra's Shortest Path Algorithm.
 * 
 * ALGORITHM:
 * 1. Maintain a list of distances from source to all nodes, initialized to INFINITY.
 * 2. Set dist[source] = 0.
 * 3. While there are unvisited nodes:
 *    a. Choose unvisited node 'u' with minimum distance.
 *    b. For each neighbor 'v' of 'u':
 *       If dist[u] + weight(u,v) < dist[v]:
 *          Update dist[v] = dist[u] + weight(u,v)
 *    c. Mark 'u' as visited.
 */

#define V 5

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
