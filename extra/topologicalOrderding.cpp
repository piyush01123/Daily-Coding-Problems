
/*
Topological Ordering/Sorting basically means an Ordering of vertices such that
for any edge (u, v); u should come before v in the Ordering.
Here we are using DFS to traverse the graph and recoversively insert to front
from node 0. Then insert 0 to the front. If it is a connected graph,
this would be enough. But for disjoint graphs, we also need to take care of
other subgraphs. So, we use the visited array to check for any remaining
vertices; then do the same for those.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Graph{
public:
  int num_vertices;
  std::unordered_map<int, std::vector<int>> edges;
  Graph(int n): num_vertices(n){}
  void add_edge(int src, int dest){
    this->edges[src].push_back(dest);
  }
};

void topologicalOrderingUtil(Graph g, std::vector<int> &vertices, std::vector<bool> &visited, int v){
  visited[v] = true;
  for (int w: g.edges[v]) if (!visited[w]) topologicalOrderingUtil(g, vertices, visited, w);
  vertices.insert(vertices.begin(), v);
}

std::vector<int> topologicalOrdering(Graph g){
  std::vector<int> vertices;
  std::vector<bool> visited(g.num_vertices, false);
  for (int i=0; i<g.num_vertices; i++){
    if (!visited[i]) topologicalOrderingUtil(g, vertices, visited, i);
  }
  return vertices;
}

int main(){
  Graph g(5);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(2, 3);
  g.add_edge(3, 4);
  std::vector<int> v = topologicalOrdering(g);
  for  (int i=0; i<v.size(); i++) std::cout << v[i] << ' ';
  std::cout << '\n';

  Graph g2(6);
  g2.add_edge(2, 3);
  g2.add_edge(4, 0);
  g2.add_edge(4, 1);
  g2.add_edge(5, 0);
  g2.add_edge(5, 2);
  std::vector<int> v2 = topologicalOrdering(g2);
  for  (int i=0; i<v2.size(); i++) std::cout << v2[i] << ' ';
  std::cout << '\n';

  return 0;
}
