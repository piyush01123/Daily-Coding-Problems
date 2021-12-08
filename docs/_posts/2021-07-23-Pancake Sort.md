---
layout: post
title: "Pancake Sort"
categories: misc
---

Given a list, sort it using this method: `reverse(lst, i, j)`, which reverses lst from i to j.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MIN -10000

void reverse(std::vector<int> &lst, int i, int j){
  std::vector<int>::iterator it = lst.begin();
  std::reverse(lst.begin()+i, lst.begin()+j+1);
}

void pancakeSort(std::vector<int> &lst){
  int n = lst.size();
  int maxElemIndex;
  for (int i=0; i<n; i++){
    int maxElem = INT_MIN;
    for (int j=0; j<n-i; j++){
      if (lst[j]>maxElem){
        maxElem = lst[j];
        maxElemIndex = j;
      }
    }
    reverse(lst, maxElemIndex, n-i-1);
  }
}

void test(){
  std::vector<int> lst = {6, 7, 9, 8, 2, 5, 3, 4, 1};
  std::cout<<"\nOriginal array\n";
  for (int n: lst) std::cout << n << " "; std::cout << std::endl;
  pancakeSort(lst);
  std::cout<<"\nSorted array\n";
  for (int n: lst) std::cout << n << " "; std::cout << std::endl;
}

int main(){
  test();
  return 0;
}
```
