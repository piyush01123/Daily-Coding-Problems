---
layout: post
title: "Min root to leaf sum path in binary tree"
categories: misc
---

This question was asked by Apple.

Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.
```
  10
 /  \
5    5
 \     \
   2    1
       /
     -1
```


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>

struct node{
  // b tree node data structure
  int data;
  node *left, *right;
};

node *createNode(int data){
  // fn to create a b tree node
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

int minPathSum(node *root){
  // min path root to leaf sum
  if (root==NULL) return 0;
  return root->data + std::min(minPathSum(root->left), minPathSum(root->right));
}

void test(){
  // builds and runs test cases
  node *root = createNode(10);
  root->left = createNode(5);
  root->left->right = createNode(2);
  root->right = createNode(5);
  root->right->right = createNode(1);
  root->right->right->left = createNode(-1);
  std::cout << minPathSum(root) << std::endl;
}

int main(){
  // run the test
  test();
  return 0;
}
```
