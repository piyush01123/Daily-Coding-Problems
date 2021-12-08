---
layout: post
title: "Most frequent subtree sum"
categories: misc
---

This problem was asked by Apple.

Given the root of a binary tree, find the most frequent subtree sum. The subtree sum of a node is the sum of all values under a node, including the node itself.

For example, given the following tree:
```
  5
 / \
2  -5
```
Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <unordered_map>

struct  node{
  int data;
  node *left, *right;
};

node *createNode(int data){
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = nullptr;
  return temp;
}

int subTreeSum(node *head){
  if (head==nullptr) return 0;
  return head->data + subTreeSum(head->left) + subTreeSum(head->right);
}

void allSubTreeSums(node *head, std::vector<int> &sum_vals){
  if (head==nullptr) return;
  sum_vals.push_back(subTreeSum(head));
  allSubTreeSums(head->left, sum_vals);
  allSubTreeSums(head->right, sum_vals);
}

int mostFrequentSubTreeSum(node *root){
  std::vector<int> sum_vals;
  allSubTreeSums(root, sum_vals);
  std::unordered_map<int, int> freq;
  for (int v: sum_vals) freq[v]++;
  int most_frequent, max_freq = 0;
  for (auto item: freq){
    if (item.second>max_freq){
      max_freq = item.second;
      most_frequent = item.first;
    }
  }
  return most_frequent;
}

void test(){
  node *root = createNode(5);
  root->left = createNode(2);
  root->right = createNode(-5);
  int most_frequent = mostFrequentSubTreeSum(root);
  std::cout<<most_frequent<<'\n';
}

int main(){
  test();
  return 0;
}
```
