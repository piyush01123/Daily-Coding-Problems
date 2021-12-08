---
layout: post
title: "Top-Left to Bottom-Right"
categories: misc
---

This problem was asked by Facebook.

There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left corner and getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:

- Right, then down
- Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.


My Solution(Python):
```

def num_ways(M, N):
    if M==1 or N==1:
        return 1
    else:
        return num_ways(M,  N-1) + num_ways(M-1, N)

print(num_ways(2, 2))
print(num_ways(2, 3))
print(num_ways(5, 5))
```
