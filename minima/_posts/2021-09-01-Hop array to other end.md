---
layout: post
title: "Hop array to other end"
categories: misc
---

This problem was asked by Pinterest.

Given an integer list where each number represents the number of hops you can make, determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.


My Solution(C++):
```

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool hopToOtherEnd(std::vector<int> A){
  int i = 0;
  while (i<A.size()) {
    if (i==A.size()-1){
      return true;
    }
    if (A[i]==0){
      return false;
    }
    i = i + A[i];
  }
  return false;
}

int main(){
  std::vector<int> A;
  A = {2, 0, 1, 0};
  cout << hopToOtherEnd(A) << endl;
  A = {1, 1,  0, 1};
  cout << hopToOtherEnd(A) << endl;
  A = {3, 1, 0, 1};
  cout << hopToOtherEnd(A) << endl;
  A = {4, 1, 0, 1};
  cout << hopToOtherEnd(A) << endl;
  A = {2, 1, 1, 0};
  cout << hopToOtherEnd(A) << endl;
  return 1;
}
```


My Solution(Python):
```

def hopToOtherEnd(A: list) -> bool:
    i = 0
    while i < len(A):
        if i==len(A)-1:
            return True
        if A[i]==0:
            return False
        i = i + A[i]
    return False


if __name__=='__main__':
    print(hopToOtherEnd([2, 0, 1, 0])) #true
    print(hopToOtherEnd([1, 1, 0, 1])) #false
    print(hopToOtherEnd([3, 1, 0, 1])) #true
    print(hopToOtherEnd([4, 1, 0, 1])) #false
    print(hopToOtherEnd([2, 1, 1, 0])) #true
```
