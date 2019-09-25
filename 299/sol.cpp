
// This is a standard SSSP  (Single Source Shortest Path) problem.
// Lets do it by Dijkstra's algorithm.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>


class Graph{
public:
  int num_vertices;
  std::unordered_map<int, std::unordered_map<int, int>> edges;
  Graph(int _n): num_vertices(_n) {}
  void add_edge(int u, int v, int d){ edges[u][v] = d; }
};


std::pair<std::unordered_map<int, int>,std::vector<std::pair<int,int>>> dijksra(Graph g, int src){
  // return {node: min_dist} hashmap.
  std::unordered_map<int, int> shortest_paths;
  std::vector<std::pair<int,int>> usefulPaths;
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
    usefulPaths.push_back(std::make_pair((*it).first, (*it).second.first));
  }
  return std::make_pair(shortest_paths, usefulPaths);
}



int minPipeRequirerd(std::unordered_map<char,std::unordered_map<char,int>> city,
  std::unordered_map<char,int> mapping){
  Graph g(city.size());
  for (auto item: city){
    int u = mapping[item.first];
    for (auto _item: item.second){
      int v = mapping[_item.first];
      int d = _item.second;
      g.add_edge(u, v, d);
      g.add_edge(v, u, d);
    }
  }
  std::pair<std::unordered_map<int, int>,std::vector<std::pair<int,int>>> res = dijksra(g, 0);
  int total_pipe_length = 0;
  for (auto item: res.second) total_pipe_length += g.edges[item.first][item.second];
  return total_pipe_length;
}


void test(){
  std::unordered_map<char,std::unordered_map<char,int>> city {
    {'P', {{'A', 1}, {'B', 5}, {'C', 20}}},
    {'A', {{'C', 15}}},
    {'B', {{'C', 10}}},
    {'C', {}}
  };
  std::unordered_map<char,int> mapping {{'P',0},{'A',1},{'B',2},{'C',3}};
  std::cout << "Total Pipe Length = " << minPipeRequirerd(city, mapping) << '\n';;
}


int main(){
  test();
  return 0;
}
