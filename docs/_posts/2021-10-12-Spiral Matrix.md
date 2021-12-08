---
layout: post
title: "Spiral Matrix"
categories: misc
---

This problem was asked by Amazon.

Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:
```
[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
```
You should print out the following:
```
1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
```


My Solution(Python):
```

def printSpiral(A):
    while A:
        top = A.pop(0)
        bottom = A.pop()
        for item in top:
            print(item)
        for rem in A:
            print(rem.pop())
        for item in bottom[::-1]:
            print(item)
        for rem in A[::-1]:
            print(rem.pop(0))

A = [[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]

printSpiral(A)
```
