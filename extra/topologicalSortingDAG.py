
from collections import defaultdict

class Graph:
    # Graph written as Adjancency List
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    @property
    def num_vertices(self):
        v_src = set(self.graph.keys())
        v_dest = set(item for sub in self.graph.values() for item in sub)
        return len(v_src.union(v_dest))


def topologicalSortUtil(graph, visited, stack, u):
    visited[u] = True
    for v in graph.graph[u]:
        if visited[v]==False:
            topologicalSortUtil(graph, visited, stack, v)
    stack.insert(0, u)


def topologicalSort(graph):
    visited = [False for _ in range(graph.num_vertices)]
    stack = []
    for i in range(graph.num_vertices):
        if visited[i]==False:
            topologicalSortUtil(graph, visited, stack, i)
    return stack



def main():
    edges = [(0, 1),
             (0, 2),
             (2, 3),
             (3, 4)]
    graph = Graph()
    for u, v in edges:
        graph.add_edge(u, v)
    top_sort = topologicalSort(graph)
    print('Topologically Sorted Vertices = %s' %top_sort)

    g = Graph()
    g.add_edge(5, 2)
    g.add_edge(5, 0)
    g.add_edge(4, 0)
    g.add_edge(4, 1)
    g.add_edge(2, 3)
    top_sort = topologicalSort(g)
    print('Topologically Sorted Vertices = %s' %top_sort)


if __name__=='__main__':
    main()
