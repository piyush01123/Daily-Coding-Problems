---
layout: post
title: "Min intervals to remove to make them non-overlapping"
categories: misc
---

This problem was asked by Stripe.

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8), return 1 as the last interval can be removed and the first two won't overlap.

The intervals are not necessarily sorted in any order.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>

struct Interval{
  int start;
  int end;
};

int makeOvelap(std::vector<Interval> v){
  //minimum no. of intervals to remove to make remaining ones non-overlapping
  auto comp_fn = [](Interval i1, Interval i2){return i1.start<i2.start;};
  std::sort(v.begin(), v.end(), comp_fn);
  int res = 0, pre = 0;
  for (int i=1; i<v.size(); i++){
    if (v[i].start<v[pre].end){
      res++;
      if (v[i].end<v[pre].end) pre = i;
    } else {
      pre = i;
    }
  }
  return res;
}

void test(){
  std::vector<Interval> intervals { {7, 9}, {2, 4}, {5, 8} };
  std::cout<<makeOvelap(intervals)<<'\n';
}

int main(){
  test();
  return 0;
}
```
