---
layout: post
title: "Max Level sum in a binary tree"
categories: misc
---

This problem was asked by Facebook.

Given a binary tree, return the level of the tree with minimum sum.


My Solution(C++):
```

#include <iostream>
#include <vector>
#define INT_MIN -100000000

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


int maxDepth(node *root){
  // Returns the maximum depth of a binary tree
  if (root == NULL) return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


void allKeysOfLevel(node *root, int level, vector<int> &keys){
  // Collects all keys of a b. tree at a level in a vector
  if (root==NULL) return;
  if (level==1){
    keys.push_back(root->data);
  }
  if (level>1){
    allKeysOfLevel(root->left, level-1, keys);
    allKeysOfLevel(root->right, level-1, keys);
  }
  return;
}


int maxLevelSum(node *root){
  // Returns the level with max level sum
  int depth = maxDepth(root);
  vector<int> v;
  int sum, level_max;
  int max_levl_sum = INT_MIN;
  for (int d=1; d<=depth; d++){
    v = {};
    sum = 0;
    allKeysOfLevel(root, d, v);
    for (int i=0; i<v.size(); i++){
      sum = sum+v[i];
    }
    if (sum>max_levl_sum)
      level_max = d;
      max_levl_sum = sum;
  }
  return level_max;
}

void test(){
  // Create and run a test case
  node *root = createNode(3);
  root->left = createNode(-3);
  root->right = createNode(7);
  root->left->left = createNode(30);
  root->left->right = createNode(50);
  root->right->left = createNode(-100);
  cout << "Level with max sum = " << maxLevelSum(root) << endl;;
}


int main(){
  // runs the test
  test();
}
```
