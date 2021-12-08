---
layout: post
title: "One-to-one character mapping between two strings"
categories: misc
---

This problem was asked by Bloomberg.

Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.


My Solution(C++):
```

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

std::vector<int> encode(std::string str){
  std::vector<char> letters;
  int ctr = 0;
  std::vector<int> v;
  for (char c: str){
    std::vector<char>::iterator it = std::find(letters.begin(), letters.end(), c);
    if (it==letters.end()){
      letters.push_back(c);
      v.push_back(ctr++);
    } else {
      int idx = it-letters.begin();
      v.push_back(idx);
    }
  }
  return v;
}

bool mappingPossible(std::string s1, std::string s2){
  std::vector<int> v1 = encode(s1);
  std::vector<int> v2 = encode(s2);
  // for (int i: v1) std::cout << i << ' '; std::cout << '\n';
  // for (int i: v2) std::cout << i << ' '; std::cout << '\n';
  return v1==v2;
}

void test(){
  std::string s1 = "abc";
  std::string s2 = "bcd";
  std::cout<<"s1 = "<<s1<<" s2 = "<<s2<<' '<<std::boolalpha<<mappingPossible(s1, s2)<<'\n';
  std::string s3 = "foo";
  std::string s4 = "bar";
  std::cout<<"s1 = "<<s3<<" s2 = "<<s4<<' '<<std::boolalpha<<mappingPossible(s3, s4)<<'\n';
}

int main(){
  // std::vector<int> v1 = encode("foooaago");
  // for (int i: v1) std::cout << i << ' '; std::cout << '\n';
  test();
  return 0;
}
```
