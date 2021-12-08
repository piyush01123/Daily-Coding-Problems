---
layout: post
title: "Integer palindrome"
categories: misc
---

This problem was asked by Palantir.

Write a program that checks whether an integer is a palindrome. For example, 121 is a palindrome, as well as 888. 678 is not a palindrome. Do not convert the integer into a string.


My Solution(C++):
```

#include <iostream>
#include <vector>

bool isPalindrome(int num){
  std::vector<int> digits;
  while (num>0){
    digits.push_back(num%10);
    num/=10;
  }
  // for (int d: digits) std::cout<<d<<' ';std::cout<<'\n';
  int n = digits.size();
  for (int i=0; i<n/2; i++){
    if (digits[i]!=digits[n-i-1]){
      return false;
    }
  }
  return true;
}

void test(){
  std::cout<<std::boolalpha<<isPalindrome(121)<<'\n';
  std::cout<<std::boolalpha<<isPalindrome(888)<<'\n';
  std::cout<<std::boolalpha<<isPalindrome(678)<<'\n';
}

int main(){
  test();
}
```
