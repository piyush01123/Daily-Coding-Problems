---
layout: post
title: "Minimum boats to rescue"
categories: misc
---

This problem was asked by Glassdoor.

An imminent hurricane threatens the coastal town of Codeville. If at most two people can fit in a rescue boat, and the maximum weight limit for a given boat is k, determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80] and a boat limit of 200, the smallest number of boats required will be three.


My Solution(C++):
```

/*
My solution is this: First sort the weights smallest to largest.
Then take largest weight w. Find cap-w. and find largest item less than  cap-w.
Take that weight.
Then repeat.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int minBoats(std::vector<int> weights, int capacity){
  std::sort(weights.begin(), weights.end());
  int ctr = 0;
  while (weights.size()>0){
    int w_max = weights.back();
    weights.pop_back();
    int i=-1;
    while (weights[i+1]<capacity-w_max) i++;
    if (i>=0) weights.erase(weights.begin()+i);
    ctr++;
  }
  return ctr;
}

int main(){
  std::vector<int> v {100, 200, 150, 80};
  int cap = 200;
  std::cout << "Min # Boats Required = " << minBoats(v, cap) << '\n';
  return 0;
}
```
