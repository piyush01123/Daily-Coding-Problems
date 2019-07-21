
#include<iostream>
#include <unordered_map>
#include <pair>
#include <algorithm>


struct node{
  // node data structure
  int data;
  node *left;
  node *right;
  node (int key){
    //constructor
    this->data = key;
    this->left = nullptr;
    this->right = nullptr;
  }
};


int depth(node *root){
  //recursively finds depth - Root has the max depth
  if (root==nullptr) return 0;
  return 1+std::max(depth(root->left), depth(root->right));
}


void bottomViewUtil(node *root, int hd, std::unordered_map<int, std::pair<int, int>> &H){
  //recursively updates a hashmap of hd->(d, val) with deepest(botoom key) in case of collision
  if (root==nullptr) return;
  int d = depth(root);
  if (H.find(hd)==H.end() || H[hd].first>d){
    H[hd] = std::make_pair(d, root->data);
  }
  printBottomViewUtil(root->left, hd-1, H);
  printBottomViewUtil(root->right, hd+1, H);
}


std::vector<int> bottomView(node *root){
  // returns a vector of bottom view from left to right
  std::unordered_map<int, std::pair<int, int>> H;
  printBottomViewUtil(root, 0, H);
  int treeDepth = depth(root);
  std::vector<int> v;

  // possible range of hd's range from -d to +d
  for (int hd=-treeDepth; hd<=treeDepth; hd++){
    if (H.find(hd) != H.end()){
      v.push_back(H[hd].second);
    }
  }
}


void test(){
  //builds a B-Tree and runs the test
  node *root = new node(5);
  root->left = new node(3);
  root->right = new node(7);
  root->left->left = new node(1);
  root->left->right = new node(4);
  root->right->left = new node(6);
  root->right->right = new node(9);
  root->left->left->left = new node(0);
  root->right->right->left =  new node(8);
  std::vector<int> v = bottomView(root);
  for (int n: v) std::cout<<n<<' '; std::cout<<'\n';
}

int main(){
  // run all fns
  test();
  return 0;
}
