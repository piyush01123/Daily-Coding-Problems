---
layout: post
title: "Balanced parantheses"
categories: misc
---

This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string `"([])[]({})"`, you should return `true`.

Given the string "`([)]"` or `"((()",` you should return `false`.


My Solution(Python):
```

def balancedBrackes(S: str) -> bool:
    ctr_rnd = 0
    ctr_crly = 0
    ctr_sqr = 0
    for char in S:
        if char=='(':
            ctr_rnd+=1
        elif char=='{':
            ctr_crly+=1
        elif char=='[':
            ctr_sqr+=1
        elif char==')':
            ctr_rnd-=1
        elif char=='}':
            ctr_crly-=1
        elif char==']':
            ctr_sqr-=1

        if ctr_rnd<0 or ctr_crly<0 or ctr_sqr<0:
            return False

    if ctr_rnd==ctr_crly==ctr_sqr==0:
        return True
    else:
        return False

if __name__=='__main__':
    print(balancedBrackes("([])[]({})"))
    print(balancedBrackes("([)]"))
    print(balancedBrackes("((()"))
```
