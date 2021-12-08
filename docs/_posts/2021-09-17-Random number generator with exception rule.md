---
layout: post
title: "Random number generator with exception rule"
categories: misc
---

This question was asked by Google.

Given an integer n and a list of integers l, write a function that randomly generates a number from 0 to n-1 that isn't in l (uniform).


My Solution(Python):
```

import random

def generateRandom(n: int, l: list):
    A = [num for num in range(n) if num not in l]
    while True:
        idx = random.randint(0, len(A)-1)
        yield A[idx]

if __name__=='__main__':
    gen = generateRandom(n=10, l=[3, 8, 12, 20])
    for _ in range(25):
        print(gen.__next__())
```
