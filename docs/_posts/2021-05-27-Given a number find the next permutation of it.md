---
layout: post
title: "Given a number find the next permutation of it"
categories: misc
---

This problem was asked by IBM.

Given an integer, find the next permutation of it in absolute order. For example, given 48975, the next permutation would be 49578.


My Solution(C++):
```


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


int nextHigherPermutation(int num){
  // returns the next higher permuation from the digits of a number
  std::vector<int> digits;
  while (num>0){
    digits.push_back(num%10);
    num = num/10;
  }
  int num_digits = digits.size(), i;
  // for (int i: digits) std::cout<<i<<',';std::cout<<'\n';
  std::vector<int> trail;
  for (i=0; i<num_digits; i++){
    trail.push_back(digits[i]);
    if (digits[i+1]<digits[i]) break;
  }
  int to_replace_pos = i+1;
  int to_replace = digits[to_replace_pos];
  for (int i=0; i<trail.size(); i++){
    if (trail[i]>to_replace){
      digits[to_replace_pos] = trail[i];
      trail[i] = to_replace;
      break;
    }
  }

  // std::cout<<"TRAIL\n";
  // for (int i: trail) std::cout<<i<<',';std::cout<<'\n';

  std::reverse(trail.begin(), trail.end());
  for (i = to_replace_pos; i<num_digits; i++) trail.push_back(digits[i]);

  // std::cout<<"TRAIL\n";
  // for (int i: trail) std::cout<<i<<',';std::cout<<'\n';

  int n = 0;
  for (int i=0; i<num_digits; i++){
    n = n+ trail[i]*pow(10, i);
  }
  return n;
}



void test(){
  std::cout<<nextHigherPermutation(48975)<<'\n'; //49578 [5, 7, 9, 8, 4]
  std::cout<<nextHigherPermutation(48070)<<'\n'; //48700 [0, 7, 0, 8, 4]
  std::cout<<nextHigherPermutation(121698765)<<'\n'; //121756689 [5, 6, 7, 8, 9, 6, 1, 2, 1]
}


int main(){
  test();
  return 0;
}
```
