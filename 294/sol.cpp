
/*
This problem can be broken down to 2 SSSP  problems:
sol1  finds minimum paths from S to every node using only  uphill paths.
sol2  finds minimum paths from T to every node using only  uphill paths.
Whichever node has minimum sum of 2 paths is the  answer.
Here S and T are same. So we need to create 2 graphs. 1 finds out min Dist from
S to all other nodes with only uphill paths. 2 finds min distance from all nodes
to S with only downhill paths. Whichever one has minimum sum gives us the answer.
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
  while (true){
    // std::cout<<"SIZE"<<shortest_paths.size()<<'\n';
    std::vector<int> next_vertices; //<v>
    for (auto item: shortest_paths){
      int u = item.first;
      for (auto t: g.edges[u]){
        int v = t.first, d = t.second;
        if (shortest_paths.find(v)==shortest_paths.end())
        next_vertices.push_back(v);
      }
    }
    if (next_vertices.size()==0) break;


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


int minRunningTrackPath(Graph g, std::unordered_map<int, int> elevations, int src){
  Graph g_uphill(g.num_vertices), g_downhill(g.num_vertices);
  for (auto item: g.edges){
    int u = item.first;
    for (auto p: item.second){
      int v = p.first;
      int d = p.second;
      if (elevations[v] > elevations[u]) g_uphill.add_edge(u, v, d);
      else g_downhill.add_edge(u, v, d);
    }
  }

  std::unordered_map<int, int> distances_up = dijksra(g_uphill, src);
  distances_up.erase(src);

  std::unordered_map<int, int> distances_down;
  for (int u=0;u<g_downhill.num_vertices;u++){
    if (u==src || g_downhill.edges[u].size()==0) continue;
    std::unordered_map<int, int> distances_down_from_each = dijksra(g_downhill, u);
    if (distances_down_from_each.find(src)!=distances_down_from_each.end())
    distances_down[u] = distances_down_from_each[src];
  }

  std::unordered_map<int,int> distances_total;
  for (auto item: distances_up)
  if (distances_down.find(item.first)!=distances_down.end())
  distances_total[item.first] = item.second+distances_down[item.first];

  auto _cmp = [](const auto &i1, const auto &i2){ return i1.second<i2.second; };
  auto it = std::min_element(distances_total.begin(), distances_total.end(), _cmp);
  int min_dist_total = (*it).second;

  return min_dist_total;
}


void test(){
  std::unordered_map<int, int> elevations {{0, 5},{1, 25},{2, 15},{3, 20},{4, 10}};
  Graph g(5);
  g.add_edge(0, 1, 10);
	g.add_edge(0, 2, 8);
	g.add_edge(0, 3, 15);
	g.add_edge(1, 3, 12);
	g.add_edge(2, 4, 10);
	g.add_edge(3, 4, 5);
	g.add_edge(3, 0, 17);
	g.add_edge(4, 0, 10);
  int min_running_track_path = minRunningTrackPath(g, elevations,0);
  std::cout << "Min Running Track Path = " << min_running_track_path << '\n';
}

int main(){
  test();
  return 0;
}
