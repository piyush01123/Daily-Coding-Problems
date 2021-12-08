---
layout: post
title: "Does string represent a number"
categories: misc
---

This problem was asked by LinkedIn.

Given a string, return whether it represents a number. Here are the different kinds of numbers:
- "10", a positive integer
- "-10", a negative integer
- "10.1", a positive real number
- "-10.1", a negative real number
- "1e5", a number in scientific notation

And here are examples of non-numbers:
- "a"
- "x 1"
- "a -2"
- "-"


My Solution(C++):
```

#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isFloat(string s){
  // solution
  try{
    float f = stof(s);
    return true;
  }
  catch(...){
    return false;
  }
}


void test(){
  // builds test cases and tests the function
  vector<string> S {"10", "-10", "10.1", "-10.1", "1e5", "a", "x 1", "a -2","-"};
  for (auto s: S){
    cout << s << " " << boolalpha << isFloat(s) << endl;
  }
}


int main(){
  // runs tests
  test();
}
```
