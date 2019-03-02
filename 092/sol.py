
class Graph:
    def __init__(self, nodes = []):
        self.nodes = nodes
        self.graph = {i: [] for i in range(len(nodes))}

    def add_edge(self, src, dest):
        self.graph[self.node_to_id[src]].append(self.node_to_id[dest])

    @property
    def num_vertices(self):
        return self.nodes.__len__()

    @property
    def node_to_id(self):
        return {v: i for i, v in enumerate(self.nodes)}

    @property
    def id_to_node(self):
        return {i: v for i, v in enumerate(self.nodes)}

    def topologicalSortUtil(self, visited, stack, u):
        visited[u] = True
        for v in self.graph[u]:
            if visited[v]==False:
                topologicalSortUtil(self.graph, visited, stack, v)
        stack.insert(0, u)
        # print('current stack', stack)

    def topologicalSort(self):
        visited = [False for _ in range(self.num_vertices)]
        stack = []
        for i in range(self.num_vertices):
            if visited[i]==False:
                self.topologicalSortUtil(visited, stack, i)
        return stack


def courseOrdering(courses: dict) -> list:
    graph = Graph(courses.keys())
    for dest, srcs in courses.items():
        for src in srcs:
            graph.add_edge(src, dest)
    # print(graph.graph)
    ordering = [graph.id_to_node[id] for id in  graph.topologicalSort()]
    return ordering


if __name__=='__main__':
    courses = {'CSC300': ['CSC100', 'CSC200'], \
               'CSC200': ['CSC100'], \
               'CSC100': []
               }
    course_order = courseOrdering(courses)
    print('-->'.join(course_order))
