# Graph Practice Questions in C

Graphs represent complex relationships between sets of objects. Study representation methods and core traversal algorithms.

## 1. Representation
- **Adjacency Matrix:** Implement a graph using a 2D array. Compare its space complexity with an adjacency list.
- **Adjacency List:** Implement a graph using an array of linked lists. This is the more common and efficient representation for sparse graphs.

## 2. Core Traversals
- **Breadth-First Search (BFS):** Implement BFS starting from a given source node. Use a queue and a `visited` array.
- **Depth-First Search (DFS):** Implement DFS (both recursive and iterative versions).

## 3. Connections & Cycles
- **Find Path:** Determine if a path exists between two nodes `U` and `V`.
- **Cycle Detection (Undirected):** Detect if a cycle exists in an undirected graph using BFS or DFS.
- **Cycle Detection (Directed):** Detect if a cycle exists in a directed graph (requires keeping track of nodes in the current recursion stack).
- **Connected Components:** Find the number of connected components in an undirected graph.

## 4. Shortest Path Algorithms
- **Shortest Path in Unweighted Graph:** Use BFS to find the shortest path between two nodes.
- **Dijkstra’s Algorithm (Basics):** Discuss the logic of finding the shortest path in a weighted graph with non-negative weights.

## 5. Advanced Challenges
- **Topological Sort:** Perform topological sorting on a Directed Acyclic Graph (DAG) using Kahn's Algorithm or DFS.
- **Check Bipartite:** Determine if a graph can be colored using only two colors such that no two adjacent nodes have the same color.
- **Mother Vertex:** Find a vertex from which all other vertices are reachable.

## C-Specific Tips
> [!CAUTION]
> - Adjacency lists involve dynamic allocation for each edge. Ensure you handle `malloc` failures and `free` all nodes when the graph is destroyed.
> - Be mindful of large graphs; an adjacency matrix of size $10^5 \times 10^5$ will easily exceed memory limits.
