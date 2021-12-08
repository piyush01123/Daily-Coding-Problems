---
layout: post
title: "In-Order successor of a node in a binary tree"
categories: misc
---

This problem was asked by Amazon.

Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.

For example, the inorder successor of 22 is 30.
```
   10
  /  \
 5    30
     /  \
   22    35
```
You can assume each node has a parent pointer.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>


struct node{
  // b tree data structure with parent
  int data;
  node *left, *right, *parent;
};


node *createNode(int data){
  // fn to create single b tree node
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = temp->parent = NULL;
  return temp;
}


node *getRoot(node *given_node){
  // find root of a b tree given any node inside it
  while (given_node->parent!=NULL) {
    given_node = given_node->parent;
  }
  return given_node;
}


void preorderTraversal(node *root, std::vector<int> &v){
  // stores preorder traversal of a b tree in a vector
  if (root==NULL) return;
  v.push_back(root->data);
  preorderTraversal(root->left, v);
  preorderTraversal(root->right, v);
}


int inOrderSuccessor(node *given_node){
  // finds the in order successor of a node,
  // if called with the highest element, returns -1
  // if called with null pointer, returns -1
  if (given_node==NULL) return -1;

  node *root = getRoot(given_node); //find root

  std::vector<int> v;
  preorderTraversal(root, v); //get all keys
  std::sort(v.begin(), v.end()); // sort

  int i = 0;
  while (v[i]<=given_node->data && i<v.size()) i++;
  if (i==v.size()){
    return -1; //you gave the highest value node
  }
  return v[i];
}


void test(){
  // builds and runs test cases
  node *root = createNode(10);
  root->left = createNode(5); root->left->parent = root;
  root->right = createNode(30); root->right->parent = root;
  root->right->left = createNode(22); root->right->left->parent = root->right;
  root->right->right = createNode(35); root->right->right->parent = root->right;

  //test cases
  node *nodes[5] = {root, root->left, root->right, root->right->left, root->right->right};
  for (int i=0; i<5; i++){
    std::cout << "In-Order Successor of " << nodes[i]->data << " is "<< inOrderSuccessor(nodes[i]) << '\n';
  }

}


int main(){
  // call the test
  test();
  return 0;
}
```
