---
layout: post
title: "Graph Coloring"
categories: misc
---

This problem was asked by Google.

Given an undirected graph represented as an adjacency matrix and an integer k, write a function to determine whether each vertex in the graph can be colored such that no two adjacent vertices share the same color using at most k colors.


My Solution(Python):
```

class Graph:
    def __init__(self, v):
        self.num_vertices = v
        self.graph = [[0 for  _ in range(v)] for _ in range(v)]

    def add_to_graph(self, adj_matrix):
        self.graph = adj_matrix


def isSafe(graph, colors, v, c):
    for i in range(graph.num_vertices):
        if graph.graph[v][i]==1 and colors[i] == c:
            return False
    return True


def graphColoringUtil(graph, k, colors, v):
    if v == graph.num_vertices:
        return True
    for c in range(1, k+1):
        if isSafe(graph, colors, v, c) == True:
            colors[v] = c
            if graphColoringUtil(graph, k, colors, v+1) == True:
                return True
            colors[v] = 0


def graphColoring(graph, k):
    colors = [0 for _ in range(graph.num_vertices)]
    if graphColoringUtil(graph, k, colors, 0) == False:
        return False
    print('Solution exists and the colors are', colors)
    return True


def main():
    """
    example graph is:
    (3)---(2)
    |   / |
    |  /  |
    | /   |
    (0)---(1)
    """

    g = Graph(4)
    adj_matrix = [[0,1,1,1], [1,0,1,0], [1,1,0,1], [1,0,1,0]]
    g.add_to_graph(adj_matrix)
    print(graphColoring(g, k=3))


if __name__=='__main__':
    main()
```
