
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;


struct node{
  // Data structure for binary tree
  int data;
  node *left, *right;
};


node *createNode(int data){
  // Useful to create a node
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}


void preOrderTraversalUtil(node *root, vector<int> &v){
  // we dont actually need a util to  do preorder traversal but if we want to return
  // a vector than we do.
  // This is the actual preorder traversal
  if (root != NULL){
    v.push_back(root->data);
    preOrderTraversalUtil(root->left, v);
    preOrderTraversalUtil(root->right, v);
  }else{
    v.push_back(-1);
  }
}


vector<int> preOrderTraversal(node *root){
  // Returning the vector
  vector<int> v;
  preOrderTraversalUtil(root, v);
  return v;
}


string serializeTree(node *root){
  // Function to serialize the tree
  vector<int> v = preOrderTraversal(root);
  if (v.size()==0){
    return "";
  }
  stringstream res;
  ostream_iterator<int> outs(res, ",");
  copy(v.begin(), v.end(), outs);
  string result = res.str();
  result.pop_back();
  return result;
}


node *helper(list<int> &preorder){
  // Useful to deserialization
  int val;
  val = preorder.front();
  preorder.pop_front();
  if (val==-1) return NULL;
  node *root = createNode(val);
  root->left = helper(preorder);
  root->right = helper(preorder);
  return root;
}


node *deserializeTree(string serialized){
 // Function for deserialization
 stringstream ss(serialized);
 list<int> preorder;
 node *root;
 string key;
 int k, val;
 while (getline(ss, key, ',')){
   k = 0;
   stringstream(key) >> k;
   preorder.push_back(k);
 }
root = helper(preorder);
return root;
}


int main(){
  // Create and run a test case
  node *root = createNode(5);
  root->left = createNode(8);
  root->right = createNode(9);
  root->right->left = createNode(10);
  string serialized = serializeTree(root);
  cout << "Serialized Tree = " << serialized << endl;
  node *root_retrieved = deserializeTree(serialized);
  string deserialized = serializeTree(root_retrieved);
  cout << "Deserialized Tree " << deserialized << endl;
  return 0;
}
