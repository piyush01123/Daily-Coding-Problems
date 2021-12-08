---
layout: post
title: "Majority Element"
categories: misc
---

This problem was asked by MongoDB.

Given a list of elements, find the majority element, which appears more than half the time `(> floor(len(lst) / 2.0))`.

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], return 1.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <unordered_map>

int majorityElement(std::vector<int> lst){
  std::unordered_map<int, int> H;
  for (int elem: lst) H[elem]++;
  for (auto item: H){
    if (item.second>=lst.size()/2){
      return item.first;
    }
  }
  return -1;
}

void test(){
  std::cout<<majorityElement({1, 2, 1, 1, 3, 4, 0})<<'\n';
}

int main(){
  test();
  return 0;
}
```
