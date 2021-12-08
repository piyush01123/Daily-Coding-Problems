---
layout: post
title: "Number of ways to climb a staircase"
categories: misc
---

This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time


My Solution(Python):
```
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # A = [1, 1]
        # for i in range(2, n+1):
        #     A.append(A[i-2] + A[i-1])
        # return A[n]

        if n==1:
            return 1
        a=1
        b=1
        for i in range(2, n+1):
            c=a+b
            a=b
            b=c
        return c
        
```
