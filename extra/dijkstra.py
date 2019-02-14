
"""
A revision of Dijkstra's algorithm: Find shortest paths to all nodes from a node
in a directed/undirected graph

Algorithm: Store the shortest paths to all nodes from a node (say Node 0) in an array.
Initially the array looks like [0, INF, INF, INF...] because except itself distance to all nodes is infinity. Also store the nodes traversed in a set S.
while S does not include every node
    do
    {
    find all nodes adjacent to nodes in S and their corresponding distances from node 0.
    Among all such nodes, add the node with the smallest distance (between itself and Node 0) to the set S and accordingly modify the distances array
    }
That's it!!

In this Implementation, the graph is stored as an adjancency matrix.
The example has 9 nodes numbered 0 through 8.
"""

def dijkstraShortestPath(graph, node):
    num_vertices = len(graph)
    assert num_vertices==len(graph[0])
    S = {node}
    dist = {i: 10**6 for i in range(num_vertices)}
    dist[node] = 0
    while len(S)<num_vertices:
        for vertex in S:
            g = graph[vertex]
            for i in range(len(g)):
                if g[i]>0:
                    dist[i] = min(g[i]+dist[vertex], dist[i])
        unseen_dist = {k: v for k, v in dist.items() if k not in S}
        nearest_vertex_from_seen_vertices = min(unseen_dist, key=unseen_dist.get)
        S.add(nearest_vertex_from_seen_vertices)
    return dist

if __name__=='__main__':
    graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
             [4, 0, 8, 0, 0, 0, 0, 11, 0],
             [0, 8, 0, 7, 0, 4, 0, 0, 2],
             [0, 0, 7, 0, 9, 14, 0, 0, 0],
             [0, 0, 0, 9, 0, 10, 0, 0, 0],
             [0, 0, 4, 14, 10, 0, 2, 0, 0],
             [0, 0, 0, 0, 0, 2, 0, 1, 6],
             [8, 11, 0, 0, 0, 0, 1, 0, 7],
             [0, 0, 2, 0, 0, 0, 6, 7, 0]
            ]
    for node in range(len(graph)):
        shortest_paths = dijkstraShortestPath(graph=graph, node=node)
        print('Shortest paths from Node %d' %node, shortest_paths)
