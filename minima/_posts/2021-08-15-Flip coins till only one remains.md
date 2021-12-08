---
layout: post
title: "Flip coins till only one remains"
categories: misc
---

This problem was asked by Microsoft.

You have n fair coins and you flip them all at the same time. Any that come up tails you set aside. The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.


My Solution(C++):
```

#include <iostream>
using namespace std;

int numFlips(int n){
  int k = 0;
  while (n>1){
    n/=2;
    k++;
  }
  return k;
}

int main(){
  cout << "n = 25, no. of flips = " << numFlips(25) << endl;
}
```
