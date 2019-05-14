
#include <vector>
#include <iostream>
#define mp std::make_pair

struct node{
  char id;
  int maxPath;
  std::vector<std::pair<node, int>> edges;
  node(char c){
    id = c;
  }
  void add_edge(node child, int wt){
    edges.push_back(mp(child, wt));
  }
  bool operator==(node other){
    return id==other.id;
  }
};


void maxPathUtil(node root){
  std::cout<<"running with root "<<root.id<<" having N(edges) = "<<root.edges.size()<<'\n';
  if (root.edges.size()==0){
    root.maxPath = 0;
    return;
  }
  int maxP = 0;
  for (auto pair: root.edges){
    maxPathUtil(pair.first);
    int cand = pair.first.maxPath+pair.second;
    // std::cout<<"Node = "<<pair.first.id<<cand<<'\n';
    maxP = (cand>maxP)?cand:maxP;
  }
  root.maxPath = maxP;
  return;
}

void check_sth(node root){
  std::cout<<root.id<<"-->"<<root.edges.size()<<'\n';
  for (auto pair: root.edges){
    node child = pair.first;
    check_sth(child);
  }
}

void test2(){
  node a = node('a');
  node b = node('b');
  node c = node('c');
  node d = node('d');
  node e = node('e');
  node f = node('f');
  node g = node('g');
  node h = node('h');
  a.edges = {mp(b, 3), mp(c, 5), mp(d, 8)};
  d.edges = {mp(e, 2), mp(f, 4)};
  e.edges = {mp(g, 1), mp(h, 1)};
  // maxPathUtil(a);
  check_sth(a);
  std::cout<<"here "<<a.edges[2].first.id<<'\n';
}

void test(){
  node a = node('a');
  node b = node('b');
  node c = node('c');
  node d = node('d');
  node e = node('e');
  node f = node('f');
  node g = node('g');
  node h = node('h');
  a.add_edge(b, 3);
  a.add_edge(c, 5);
  a.add_edge(d, 8);
  d.add_edge(e, 2);
  d.add_edge(f, 4);
  e.add_edge(g, 1);
  e.add_edge(h, 1);
  std::cout<<"test1 "<<d.edges.size()<<'\n';
  node x = a.edges[2].first;
  std::cout<<"test2 "<<x.id<<x.edges.size()<<'\n';
  bool y = d==x;
  std::cout<<std::boolalpha<<y<<'\n';
}

int main(){
  test();
  return 0;
}
