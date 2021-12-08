---
layout: post
title: "Non-duplicated item in array"
categories: misc
---

This problem was asked by Google.

Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

For example, given `[6, 1, 3, 3, 3, 6, 6]`, return 1. Given `[13, 19, 13, 13]`, return 19.

Do this in O(N) time and O(1) space.


My Solution(Python):
```

def findNonDuplicated(A: list) -> int:
    """O(N) time and O(N) space"""
    H = dict()
    for a in A:
        if a not in H:
            H[a] = 1
        else:
            H[a] += 1
    H = {val:key for key, val in H.items()}
    return H[1]


def findNonDuplicatedSol_2(A: list) -> int:
    """O(N) time and O(1) space"""
    seenOnce, seenTwice = set(), set()
    for a in A:
        if a in seenOnce:
            seenOnce.remove(a)
            seenTwice.add(a)
        elif a in seenTwice:
            seenTwice.remove(a)
        else:
            seenOnce.add(a)
    return seenOnce.pop()


if __name__=='__main__':
    A = [6, 1, 3, 3, 3, 6, 6]
    print(findNonDuplicated(A))
    print(findNonDuplicatedSol_2(A))
    A = [13, 19, 13, 13]
    print(findNonDuplicated(A))
    print(findNonDuplicatedSol_2(A))
```
