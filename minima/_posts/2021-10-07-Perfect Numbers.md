---
layout: post
title: "Perfect Numbers"
categories: misc
---

This problem was asked by Microsoft.

A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.


My Solution(Python):
```

def perfectNumber(n):
    ctr=1
    num=19
    while ctr<=n:
        a, b = num//10, num%10
        num = 10*(a+1) + (b-1)
        if sum(list(map(int, str(num)))) !=10:
            continue
        print(ctr, num)
        ctr+=1

    return num

print(perfectNumber(1000))
```
