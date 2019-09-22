
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

struct node{
    int key;
    node *left, *right;
    node(int key){
        this->key = key;
        this->left = this->right = nullptr;
    }
};

int depth(node *root){
    if (root==nullptr) return 0;
    return 1+std::max(depth(root->left), depth(root->right));
}

void getAllKeysAtDepth(node *root, int d, std::vector<int> &values){
    if (root==nullptr) return;
    getAllKeysAtDepth(root->left, d, values);
    if (depth(root)==d) values.push_back(root->key);
    getAllKeysAtDepth(root->right, d, values);
}

std::vector<int> boustrophedon(node *root){
    std::vector<int> answer;
    int treeDepth = depth(root);
    bool dirn = true;
    for (int d=treeDepth; d>=1; d--){
        std::vector<int> values;
        getAllKeysAtDepth(root, d, values);
        if (dirn) for (int i=0; i<values.size(); i++) answer.push_back(values[i]);
        else for (int i = values.size()-1; i>=0; i--) answer.push_back(values[i]);
        dirn = !dirn;
    }
    return answer;
}

std::vector<int> boustrophedon_BFS(node *root){
  std::vector<int> v;
  std::list<node *> Q;
  Q.push_back(root);
  while (!Q.empty()){
    node *p = Q.front();
    Q.pop_front();
    v.push_back(p->key);
    if (p->left) Q.push_back(p->left);
    if (p->right) Q.push_back(p->right);
  }
  return v;
}

void test(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    std::vector<int> keys = boustrophedon(root);
    for (int i=0; i<keys.size(); i++) std::cout << keys[i] << ' '; std::cout<<'\n';
    std::vector<int> keys_v2 = boustrophedon_BFS(root);
    for (int i=0; i<keys_v2.size(); i++) std::cout << keys_v2[i] << ' '; std::cout<<'\n';
}

int main(){
    test();
    return 0;
}
