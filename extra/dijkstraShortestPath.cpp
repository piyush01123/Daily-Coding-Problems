
/*
Directed Graph SSSP(Single Source Shortest Path) Solution by Dijkstra algorithm.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>


class Graph{
public:
  int num_vertices;
  std::unordered_map<int, std::vector<std::pair<int, int>>> edges;
  Graph(int _n): num_vertices(_n) {}
  void add_edge(int u, int v, int d){ edges[u].push_back(std::make_pair(v, d)); }
};


std::unordered_map<int, int> dijksra(Graph g, int src){
  // return {node: min_dist} hashmap.
  std::unordered_map<int, int> shortest_paths;
  shortest_paths[src] = 0;
  while (shortest_paths.size()<g.num_vertices){
    std::vector<std::pair<int,std::pair<int,int>>> next_vertices_from_visited; //<u,<v,d>>
    for (auto item: shortest_paths){
      int u = item.first;
      for (auto t: g.edges[u]){
        int v = t.first, d = t.second;
        if (shortest_paths.find(v)==shortest_paths.end())
        next_vertices_from_visited.push_back(std::make_pair(u,
          std::make_pair(v,d+shortest_paths[u])));
      }
    }

    auto _cmp = [](const std::pair<int, std::pair<int,int>> &p1,
      const std::pair<int,std::pair<int,int>> &p2){
        return p1.second.second<p2.second.second;
      };

    auto it =  std::min_element(next_vertices_from_visited.begin(), next_vertices_from_visited.end(),
    _cmp);
    shortest_paths[(*it).second.first] = (*it).second.second;
  }
  return shortest_paths;
}


int main(){
  Graph g(9);
  g.add_edge(0, 1, 4);
  g.add_edge(0, 7, 8);
  g.add_edge(1, 0, 4);
  g.add_edge(1, 2, 8);
  g.add_edge(1, 7, 11);
  g.add_edge(2, 1, 8);
  g.add_edge(2, 3, 7);
  g.add_edge(2, 5, 4);
  g.add_edge(2, 8, 2);
  g.add_edge(3, 2, 7);
  g.add_edge(3, 4, 9);
  g.add_edge(3, 5, 14);
  g.add_edge(4, 3, 9);
  g.add_edge(4, 5, 10);
  g.add_edge(5, 2, 4);
  g.add_edge(5, 3, 14);
  g.add_edge(5, 4, 10);
  g.add_edge(5, 6, 2);
  g.add_edge(6, 5, 2);
  g.add_edge(6, 7, 1);
  g.add_edge(6, 8, 6);
  g.add_edge(7, 0, 8);
  g.add_edge(7, 1, 11);
  g.add_edge(7, 6, 1);
  g.add_edge(7, 8, 7);
  g.add_edge(8, 2, 2);
  g.add_edge(8, 6, 6);
  g.add_edge(8, 7, 7);
  for (int i=0; i<g.num_vertices; i++){
    std::cout << "Source = " << i << '\n';
    std::unordered_map<int, int> H = dijksra(g, i);
    for (auto j: H) std::cout << j.first<< ':' << j.second << '\n';
  }
  std::vector<std::pair<int,std::pair<int,int>>> next_vertices_from_visited;
  std::pair<int,int> t(2,3);
  next_vertices_from_visited.push_back(std::make_pair(1, t));
  return 0;
}
