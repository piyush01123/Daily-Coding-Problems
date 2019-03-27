
#include <iostream>
#include <vector>

using namespace std;

struct node{
  // Binary Tree data structure
  int data;
  node *left, *right;
};


node *createNode(int val){
  // Function to create a binary tree node
  node *temp = new node;
  temp->data = val;
  temp->left = temp->right = NULL;
  return temp;
}


bool findPath(node *root, node *node_to_find, vector<node> &path){
  // Builds a vector of nodes from root to node_to_find
  if (root==NULL)
    return false;
  path.push_back(*root);
  if (root==node_to_find)
    return true;
  if ((root->left!=NULL && findPath(root->left,  node_to_find, path)) || \
     (root->right!=NULL && findPath(root->right,  node_to_find, path)))
        return true;
  path.pop_back();
  return false;
}


int findLCA(node *root, node *v, node *w){
  // Returns LCA of nodes v and w in a b. tree rooted under root
  vector<node> path_v,  path_w;
  findPath(root, v, path_v);
  findPath(root, w, path_w);
  int i = 0;
  while (i<path_v.size()){
    if (path_v[i].data != path_w[i].data) break;
    i++;
  }
  return path_v[i-1].data;
}


void test(){
  // Create and run a test case
  node *root = createNode(1);
  node *l = root->left = createNode(2);
  node *r = root->right = createNode(3);
  node *ll = root->left->left = createNode(4);
  node *lr = root->left->right = createNode(5);
  node *rl = root->right->left = createNode(6);
  node *rr = root->right->right = createNode(7);
  // vector<node> path;
  // findPath(root, rl, path);
  // for (int i=0; i<path.size(); i++){
  //   cout << path[i].data << endl;
  // }

  int lca = findLCA(root, rl, rr);
  cout << "V = " << rl->data << " W = " << rr->data << " LCA = " << lca << endl;

}


int main(){
  // runs the test
  test();
}
