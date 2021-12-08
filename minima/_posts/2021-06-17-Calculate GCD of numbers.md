---
layout: post
title: "Calculate GCD of numbers"
categories: misc
---

This problem was asked by Amazon.

Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.


My Solution(C++):
```

#include <iostream>
#include <vector>

int gcd(int a, int b){
  int c;
  while (a%b>0){
    c = a%b;
    a = b;
    b = c;
  }
  return b;
}

int gcd_N(std::vector<int> v){
  if (v.size()==1){
    return v[0];
  } else if (v.size()==0){
    return -1;
  }
  int ans = gcd(v[0], v[1]);
  for (int i=2; i<v.size(); i++){
    ans = gcd(ans, v[i]);
  }
  return ans;
}

void test(){
  std::cout<<gcd_N({42, 56, 14})<<'\n';
}

int main(){
  test();
  return 0;
}
```
