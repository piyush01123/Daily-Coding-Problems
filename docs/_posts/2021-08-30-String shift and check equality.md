---
layout: post
title: "String shift and check equality"
categories: misc
---

This problem was asked by Google.

Given two strings A and B, return whether or not A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.


My Solution(Python):
```

def shiftAB(A: str, B: str) -> bool:
    if len(A) != len(B):
        return False
    for i in range(len(A)):
        if A[i:] + A[:i] == B:
            return True
    return False



if __name__=='__main__':
    print(shiftAB('abcde', 'cdeab'))
    print(shiftAB('abc', 'acb'))
    print(shiftAB('aaba', 'abaa'))
```
