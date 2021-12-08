---
layout: post
title: "Max Sum Subarray or Kadane's algorithm"
categories: misc
---

This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.


My Solution(Python):
```

def maxSumSubarray(A: list) -> int:
    max_so_far = 0
    max_ending_here = 0
    for a in A:
        max_ending_here = max_ending_here + a
        if max_ending_here < 0:
            max_ending_here = 0
        if max_ending_here > max_so_far:
            max_so_far = max_ending_here
        print('a=%i, meh=%i, msf=%s' %(a, max_ending_here, max_so_far))
    return max_so_far

A = [34, -50, 42, 14, -5, 86]
print(maxSumSubarray(A))
A = [-5, -1, -8, -9]
print(maxSumSubarray(A))
A = [34, -16]
print(maxSumSubarray(A))
A = [-16, 34]
print(maxSumSubarray(A))
```
