---
layout: post
title: "Max triplet product"
categories: misc
---

This problem was asked by Facebook.

Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.


My Solution(Python):
```

def maxProductIter(A):
    # O(N^3)
    import itertools
    combs = itertools.combinations(A, 3)
    prods = [a[0]*a[1]*a[2] for a in combs]
    return max(prods)

def maxProductSort(A):
    # O(NlogN)
    A = sorted(A)
    p1 = A[0]*A[1]*A[-1]
    p2 = A[-1]*A[-2]*A[-3]
    return max(p1, p2)

def maxProductWithoutSort(A):
    # O(N)
    minA, minA2, maxA, maxA2, maxA3 = A[0], A[0], A[0], A[0], A[0]
    for a in A:
        if a>=maxA:
            maxA = a
        elif a<maxA and a>=maxA2:
            maxA2 = a
        elif a<maxA2 and a>=maxA3:
            maxA3 = a
        if a<=minA:
            minA = a
        elif a>minA and a<=minA2:
            minA2 = a
    p1 = minA*minA2*maxA
    p2 = maxA*maxA2*maxA3
    return max(p1, p2)


A =  [-10, -10, 5, 2]
print(maxProductIter(A))
print(maxProductSort(A))
print(maxProductWithoutSort(A))
```
