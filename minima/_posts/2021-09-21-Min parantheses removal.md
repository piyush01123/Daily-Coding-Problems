---
layout: post
title: "Min parantheses removal"
categories: misc
---

This problem was asked by Google.

Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid (i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.


My Solution(Python):
```

def validParantheses(S: str) -> bool:
    if set(S).union({"(", ")"}) != {"(", ")"}:
        return "Invalid characters found"
    ctr = 0
    for char in S:
        if char=="(":
            ctr+=1
        elif char==")":
            ctr-=1
        if ctr<0:
            return False
    if ctr!=0:
        return False
    return True


def minParanthesesRemoval(S: str) -> int:
    ctr = 0
    ans = 0
    for char in S:
        if char=="(":
            ctr+=1
        elif char==")":
            ctr-=1
        if ctr<0:
            ans+=1
            ctr+=1
    return ans+ctr


if __name__=='__main__':
    print(minParanthesesRemoval("()())()"))
    print(minParanthesesRemoval(")("))
```
