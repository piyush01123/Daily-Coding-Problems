---
layout: post
title: "Largest Value Path in a Directed Graph"
categories: misc
---

This problem was asked by Google.

In a directed graph, each node is assigned an uppercase letter. We define a path's value as the number of most frequently-occurring letter along that path. For example, if a path in the graph goes through "ABACA", the value of the path is 3, since there are 3 occurrences of 'A' on the path.

Given a graph with n nodes and m directed edges, return the largest value path of the graph. If the largest value is infinite, then return null.

The graph is represented with a string and an edge list. The i-th character represents the uppercase letter of the i-th node. Each tuple in the edge list (i, j) means there is a directed edge from the i-th node to the j-th node. Self-edges are possible, as well as multi-edges.

For example, the following input graph:
```
ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]
```
Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).

The following input graph:
```
A
[(0, 0)]
```
Should return null, since we have an infinite loop.


My Solution(Python):
```

from collections import defaultdict
import itertools


class Graph:
    # Graph written as Adjancency List
    def __init__(self, node_vals):
        self.graph = defaultdict(list)
        self.node_dict = {i: node_vals[i] for i in range(len(node_vals))}
        self.num_vertices = len(node_vals)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    @property
    def adj_matrix(self):
        mat = []
        for v in range(self.num_vertices):
            mat.append(self.graph[v])
        return mat


def dfsutil(graph, visited, u):
    visited[u] = True
    print('Visited Node', u, 'Current status=', visited)
    for v in graph.graph[u]:
        if visited[v] == False:
            dfsutil(graph, visited, v)


def dfs(graph, u):
    visited = [False for _ in range(graph.num_vertices)]
    dfsutil(graph, visited, u)


def cyclicutil(graph, visited, stack, u):
    visited[u] = True
    stack[u] = True
    for v in graph.graph[u]:
        if visited[v]==False:
            if cyclicutil(graph, visited, stack, v)==True:
                return True
        elif visited[v]==True:
            if stack[v]==True:
                return True
    stack[u] = False
    return False


def detected_cycle(graph):
    visited = [False for _ in range(graph.num_vertices)]
    stack = [False for _ in range(graph.num_vertices)]
    for u in range(graph.num_vertices):
        if visited[u]==False:
            if cyclicutil(graph, visited, stack, u)==True:
                return True
    return False


# def find_path_util(graph, visited, s, d, path):
#     visited[s] = True
#     path.append(s)
#     if s==d:
#         print(path)
#     else:
#         for i in graph.graph[s]:
#             if visited[i]==False:
#                 find_path_util(graph, visited, i, d, path)
#     path.pop()
#     visited[s]= False
#
#
# def find_all_paths_sd(graph, s, d):
#     # Finds all paths between s and d by DFS. Uses Adjancency List
#     print('S=', s, 'D=', d)
#     visited = [False for _ in range(graph.num_vertices)]
#     all_paths_sd = find_path_util(graph, visited, s, d, path=[])
#     print('all_paths_sd', all_paths_sd)
#     return [[0,2,3],[0,3]]


def find_all_paths_sd(g, src, dest):
    # Finds all paths between s and d by BFS. Uses Adjancency Matrix
    path = [src]
    queue = [path]
    paths = []
    while len(queue)>0:
        path = queue.pop(0)
        last = path[-1]
        # print('BEFORE path, last, queue', path, last, queue)
        if last==dest:
            paths.append(path)
        for node in g[last]:
            if node not in path:
                newpath = path.copy()
                newpath.append(node)
                queue.append(newpath)
        # print('AFTER path, last, queue', path, last, queue)
    return paths


def list_all_paths(graph):
    all_paths = []
    for s, d in itertools.permutations(range(graph.num_vertices), 2):
        found_paths = find_all_paths_sd(graph.adj_matrix, s, d)
        print('S D PATHS', s, d, found_paths)
        all_paths.extend(found_paths)
    return all_paths


def maxValue(graph: 'Graph') -> int:
    if detected_cycle(graph) == True:
        print('Cycle Detected')
        return None
    print('No Cycle Detected')
    all_paths = list_all_paths(graph)
    max_val = 0
    for path in all_paths:
        path_vals = [graph.node_dict[node] for node in path]
        path_val_freq = defaultdict(int)
        for val in path_vals:
            path_val_freq[val]+=1
        print('path=%s, path_vals=%s, path_val_freq=%s' %(path, path_vals, path_val_freq))
        max_val = max(max_val, max(path_val_freq.values()))
    return max_val


def main():
    edges = [(0, 1),
             (0, 2),
             (2, 3),
             (3, 4)]
    graph = Graph('ABACA')
    for u, v in edges:
        graph.add_edge(u, v)
    print('Answer=', maxValue(graph))

    graph = Graph('A')
    graph.add_edge(0, 0)
    print('Answer=', maxValue(graph))

if __name__=='__main__':
    main()
```
