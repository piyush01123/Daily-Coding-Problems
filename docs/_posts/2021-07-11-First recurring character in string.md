---
layout: post
title: "First recurring character in string"
categories: misc
---

This problem was asked by Google.

Given a string, return the first recurring character in it, or null if there is no recurring character.

For example, given the string "acbbac", return "b". Given the string "abcdef", return null.


My Solution(C++):
```

#include <iostream>
#include <cstring>
#include <set>

char firstRecurChar(std::string str){
  std::set<char> chars;
  for (char c: str){
    if (chars.find(c)!=chars.end()){
      return c;
    }
    chars.insert(c);
  }
  return '\0'; //null char 
}

void test(){
  std::cout<<firstRecurChar("acbbac")<<'\n';
  std::cout<<firstRecurChar("abcdef")<<'\n';
}

int main(){
  test();
  return 0;
}
```
