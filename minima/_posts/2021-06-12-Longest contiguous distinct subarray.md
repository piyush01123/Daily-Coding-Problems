---
layout: post
title: "Longest contiguous distinct subarray"
categories: misc
---

This problem was asked by Google.

Given an array of elements, return the length of the longest subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <unordered_map>

int longestDistinctSubarray(std::vector<int> v){
  int maxL = 0, cur;
  int startLongest = 0; //starting index of the longest distinct subarray
  std::unordered_map<int, int> H;
  for (int i=0; i<v.size(); i++){
    if (H.find(v[i])!=H.end()){
      startLongest = H[v[i]]+1;
      cur = i-startLongest;
      maxL = (cur>maxL)?cur:maxL;
    }
    H[v[i]] = i;
  }
  return maxL;
}

void test(){
  std::vector<int> A {5, 1, 3, 5, 2, 3, 4, 1};
  int maxL = longestDistinctSubarray(A);
  std::cout<<maxL<<'\n';
}


int main(){
  test();
  return 0;
}
```
