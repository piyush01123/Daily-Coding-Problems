---
layout: post
title: "Max Run with at most two discrete elements"
categories: misc
---

This problem was asked by Google.

A girl is walking along an apple orchard with a bag in each hand. She likes to pick apples from each tree as she goes along, but is meticulous about not putting different kinds of apples in the same bag.

Given an input describing the types of apples she will pass on her path, in order, determine the length of the longest portion of her path that consists of just two types of apple trees.

For example, given the input [2, 1, 2, 3, 3, 1, 3, 5], the longest portion will involve types 1 and 3, with a length of four.


My Solution(C++):
```

#include <iostream>

int maxRun(int A[], int n){
  int i = 0, j, k, max_run_till_now;
  max_run_till_now = 0;
  while (i<n){
    j = i;
    while (j<n && A[j]==A[i]) j++;
    k=j;
    while (j<n && (A[j]==A[i]||A[j]==A[k])) j++;
    max_run_till_now = ((j-i)>max_run_till_now)?(j-i):max_run_till_now;
    i = k;
  }
  return max_run_till_now;
}

int main(){
  int A[] {2, 1, 2, 3, 3, 1, 3, 5};
  int n = sizeof(A)/sizeof(A[0]);
  std::cout << "Max Run = " << maxRun(A, n) << '\n';
  return 0;
}
```
