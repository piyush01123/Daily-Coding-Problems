---
layout: post
title: "2-Sum problem in binary tree"
categories: misc
---

This problem was asked by Google.

Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20
```
    10
   /   \
 5      15
       /  \
     11    15
```
Return the nodes 5 and 15.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


struct node{
  // b. tree data structure
  int data;
  node *left, *right;
};


node *createNode(int data){
  // create a b. tree node
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}


void sumNodes(node *root, int k, unordered_set<int> &comps, vector<int> &v){
  // recursively find pair
  if (comps.find(root->data) != comps.end()) v = {root->data, k-root->data};
  comps.insert(k-root->data);
  if (root->left != NULL) sumNodes(root->left, k, comps, v);
  if (root->right != NULL) sumNodes(root->right, k, comps, v);
}


void test(){
  // crates and runs soln with test case
  node *root = createNode(10);
  root->left = createNode(5);
  root->right = createNode(15);
  root->right->left = createNode(11);
  root->right->right = createNode(15);
  unordered_set<int> comps;
  vector<int> v;
  sumNodes(root, 20, comps, v);
  if (v.size()==0) cout << "Pair not found\n";
  cout << "K = 20, required nodes = {" << v[0] << ", " << v[1] << "}\n";
}


int main(){
  // run test
  test();
}
```
