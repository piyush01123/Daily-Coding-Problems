---
layout: post
title: "Integer division"
categories: misc
---

This question was asked by ContextLogic.

Implement division of two positive integers without using the division, multiplication, or modulus operators. Return the quotient as an integer, ignoring the remainder


My Solution(Python):
```

def division(a: int, b: int) -> int:
    ctr = 0
    while a>=b:
        a-=b
        ctr+=1
    return ctr

if __name__=='__main__':
    print(division(73, 7))
    print(division(121, 11))
```
