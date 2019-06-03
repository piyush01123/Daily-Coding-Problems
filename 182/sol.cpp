
/*
Minimally connected graphs and trees are equivalent and have the property that |E| = |V|-1.
We'll use this property here.
*/

#include <iostream>
#include <vector>

class Graph{
  int num_vertices;
  std::vector<int> *adj_list;
public:
  Graph(int a){
    num_vertices = a;
    adj_list = new std::vector<int>[num_vertices];
  }
  void add_edge(int u, int v){
    adj_list[u].push_back(v);
  }
  bool isMinimallyConnected(){
    int num_edges = 0;
    for (int i=0; i<num_vertices; i++){
      num_edges+=adj_list[i].size();
    }
    return num_edges==num_vertices-1;
  }
};

void test(){
  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(2, 3);
  std::cout<<std::boolalpha<<g.isMinimallyConnected()<<'\n';
  g.add_edge(3, 0);
  std::cout<<std::boolalpha<<g.isMinimallyConnected()<<'\n';
}

int main(){
  test();
  return 0;
}
