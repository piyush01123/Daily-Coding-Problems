---
layout: post
title: "Recover BST from its postorder traversal"
categories: misc
---

This problem was asked by Google.

Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:
```
    5
   / \
  3   7
 / \   \
2   4   8
```


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>

struct node{
  // binary tree node data structure
  int data;
  node *left;
  node *right;
};

node *createNode(int data){
  // get a node pointer with given int
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = nullptr;
  return temp;
}

int getDepth(node *root){
  // get the depth of a tree
  if (root==nullptr){
    return 0;
  }
  return 1 + std::max(getDepth(root->left), getDepth(root->right));
}

void getAllKeysOfLevel(node *root, int level, std::vector<int> &v){
  // appends keys of given level in passed vector. This is possible because
  // we are passing the vector by reference
  if (level==0 && root!=nullptr){
    v.push_back(root->data);
  }
  if (level>0){
    getAllKeysOfLevel(root->left, level-1, v);
    getAllKeysOfLevel(root->right, level-1, v);
  }
}

void printTreeLevelWise(node *root){
  // prints a tree level-wise
  int depth = getDepth(root);
  for (int i=0; i<depth; i++){
    std::vector<int> v;
    getAllKeysOfLevel(root, i, v);
    for (int j=0; j<v.size(); j++) std::cout<<v[j]<<' '; std::cout<<'\n';
  }
}

void testPrintTree(){
  // test the function printTreeLevelWise
  node *root = createNode(5);
  root->left = createNode(3);
  root->right = createNode(7);
  root->left->left  = createNode(2);
  root->left->right = createNode(4);
  root->right->right = createNode(8);
  printTreeLevelWise(root);
}

node *recoverBST(std::vector<int> postorder){
  // recovers a BST from a vector containing post-order traversal
  if (postorder.size()==0){
    return nullptr;
  }
  int top = postorder.back();
  postorder.pop_back();
  node *root = createNode(top);
  std::vector<int> left, right;
  for (int num: postorder){
    if (num<=top) left.push_back(num);
    else right.push_back(num);
  }
  root->left = recoverBST(left);
  root->right = recoverBST(right);
  return root;
}

void testRecoverBST(){
  // test the function recoverBST
  std::vector<int> v = {2, 4, 3, 8, 7, 5};
  node *root = recoverBST(v);
  printTreeLevelWise(root);
}

int main(){
  // run everything
  std::cout << "test PrintTree" << '\n';
  testPrintTree();
  std::cout << "test RecoverBST" << '\n';
  testRecoverBST();
  return 0;
}
```
