---
layout: post
title: "Apply a permutation on an array"
categories: misc
---

This problem was asked by Twitter.

A permutation can be specified by an array P, where P[i] represents the location of the element at i in the permutation. For example, [2, 1, 0] represents the permutation where elements at the index 0 and 2 are swapped.

Given an array and a permutation, apply the permutation to the array. For example, given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].


My Solution(C++):
```

/*
Apply a permutation on an array
*/

#include <iostream>

template<typename T>
T *apply_permutation(T arr[], int perm[], int size){
  T *arr2 = new T[size];
  for (int i=0; i<size; i++){
    arr2[i] = arr[perm[i]];
  }
  return arr2;
}

void test(){
  char A[] = {'a', 'b', 'c'};
  int P[] = {2, 1, 0};
  char *B = apply_permutation<char>(A, P, 3);
  for (int i=0; i<3; i++) std::cout<<B[i]<<',';std::cout<<'\n';
}


int main(){
  test();
  return 0;
}
```
