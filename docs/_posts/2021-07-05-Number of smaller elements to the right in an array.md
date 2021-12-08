---
layout: post
title: "Number of smaller elements to the right in an array"
categories: misc
---

This problem was asked by Google.

Given an array of integers, return a new array where each element in the new array is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

- There is 1 smaller element to the right of 3
- There is 1 smaller element to the right of 4
- There are 2 smaller elements to the right of 9
- There is 1 smaller element to the right of 6
- There are no smaller elements to the right of 1


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> smallerElements(std::vector<int> arr){
  std::vector<int> stack, final;
  for (int i=arr.size()-1; i>=0; i--){
    while(stack.size()>0 && arr[i]<stack.back()){
      stack.pop_back();
      // std::sort(stack.begin(), stack.end());
    }
    final.push_back(stack.size());
    stack.push_back(arr[i]);
    // std::cout<<"I = "<<i<<" stack now = \n";
    // for (int i: stack) std::cout<<i<<' ';std::cout<<'\n';
  }
  std::reverse(final.begin(), final.end());
  return final;
}

void test(){
  std::vector<int> A, B, C, D;
  A = {3, 4, 9, 6, 1};
  B = smallerElements(A);
  for (int b: B) std::cout<<b<<' ';std::cout<<'\n';
  C = {3, 4, 6, 2, 9};
  D = smallerElements(C);
  for (int d: D) std::cout<<d<<' ';std::cout<<'\n';
}

int main(){
  test();
  return 0;
}
```
