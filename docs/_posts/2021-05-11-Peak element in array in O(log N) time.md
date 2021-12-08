---
layout: post
title: "Peak element in array in O(log N) time"
categories: misc
---

This problem was asked by Sumo Logic.

Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both its left and right neighbors. It is guaranteed that the first and last elements are lower than all others.


My Solution(C++):
```

// we'll create a variant of binary search for this.

#include <iostream>
#include <vector>

int findPeak(std::vector<int> v){
  int l=0, r=v.size()-1;
  int mid=(l+r)/2;
  while (1){
    if (v[mid]>v[mid-1] && v[mid]>v[mid+1]) return v[mid];
    if (v[mid]>v[mid-1] && v[mid]<v[mid+1]) l = mid+1;
    if (v[mid]<v[mid-1] && v[mid]>v[mid+1]) r = mid-1;
    mid = (l+r)/2;
  }
}

int main(){
  std::vector<int> v {1,6,3,5,8,7,4,2};
  int peak = findPeak(v);
  std::cout<<peak<<'\n';
  return 0;
}
```
