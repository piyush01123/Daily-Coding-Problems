---
layout: post
title: "Palindrome string permutation possible"
categories: misc
---

This problem was asked by Amazon.

Given a string, determine whether any permutation of it is a palindrome.

For example, "carrace" should return `true`, since it can be rearranged to form "racecar", which is a palindrome. "daily" should return `false`, since there's no rearrangement that can form a palindrome.


My Solution(C++):
```

#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>

bool isPermPalin(std::string str){
  std::set<char> chars;
  for (char c: str){
    if (std::find(chars.begin(), chars.end(), c)!=chars.end()){
      //c is in chars set
      chars.erase(c);
    }
    else{
      chars.insert(c);
    }
  }
  return chars.size()<2;
}

void test(){
  std::cout<<std::boolalpha<<isPermPalin("carrace")<<'\n';
  std::cout<<std::boolalpha<<isPermPalin("daily")<<'\n';
  std::cout<<std::boolalpha<<isPermPalin("dailydaly")<<'\n';
}

int main(){
  test();
  return 0;
}
```
