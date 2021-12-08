---
layout: post
title: "Reverse bits"
categories: misc
---

This problem was asked by Facebook.

Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111.


My Solution(C++):
```

#include <string>
#include <iostream>

std::string reverseBitString(std::string bits){
  std::string rev;
  for (char b: bits){
    if (b=='0') rev.push_back('1');
    else rev.push_back('0');
  }
  return rev;
}

int main(){
  std::string bits = "11110000111100001111000011110000";
  std::string bitRev = reverseBitString(bits);
  std::cout<<"original="<<bits<<"\nreversed="<<bitRev<<'\n';
  return 0;
}
```
