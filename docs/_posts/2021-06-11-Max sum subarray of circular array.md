---
layout: post
title: "Max sum subarray of circular array"
categories: misc
---

This problem was asked by Facebook.

Given a circular array, compute its maximum subarray sum in O(n) time. A subarray can be empty, and in this case the sum is 0.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.


My Solution(C++):
```

#include <iostream>
#include <vector>

int kadaneMaxSubarray(std::vector<int> v){
  int max_so_far = 0, max_ending_here = 0;
  for (int a: v){
    max_ending_here+=a;
    max_ending_here = (max_ending_here<0)?0:max_ending_here;
    max_so_far = (max_ending_here>max_so_far)?max_ending_here:max_so_far;
  }
  return max_so_far;
}

void testKadane(){
  std::vector<int> A {8, -8, 3, 4};
  std::cout<<kadaneMaxSubarray(A)<<'\n';
}

int maxCircularSum(std::vector<int> v){
  int simple_max_sum = kadaneMaxSubarray(v);
  int size = v.size();
  int max_wrap = 0;
  for (int i=0; i<size; i++){
    max_wrap+=v[i];
    v[i] = -v[i];
  }
  max_wrap = max_wrap+kadaneMaxSubarray(v);
  return (max_wrap>simple_max_sum)?max_wrap:simple_max_sum;
}

void test(){
  std::vector<int> A {8, -1, 3, 4};
  std::cout<<maxCircularSum(A)<<'\n';
  std::vector<int> B {-4, 5, 1, 0};
  std::cout<<maxCircularSum(B)<<'\n';
}

int main(){
  // testKadane();
  test();
  return 0;
}
```
