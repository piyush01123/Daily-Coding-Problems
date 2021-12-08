---
layout: post
title: "Next greater permutation"
categories: misc
---

This problem was asked by Palantir.

Given a number represented by a list of digits, find the next greater permutation of a number, in terms of lexicographic ordering. If there is not greater permutation possible, return the permutation with the lowest value/ordering.

For example, the list `[1,2,3]` should return `[1,3,2]`. The list `[1,3,2]` should return `[2,1,3]`. The list `[3,2,1]` should return `[1,2,3]`.

Can you perform the operation without allocating extra memory (disregarding the input memory)?


My Solution(Python):
```

def allPossiblePermutations(lst):
    if len(lst)==0:
        return []
    if len(lst)==1:
        return [lst]
    all_perms = []
    for i in range(len(lst)):
        item = lst[i]
        rem = lst[:i] + lst[i+1:]
        perms = allPossiblePermutations(rem)
        for perm in perms:
            all_perms.append([item]+perm)
    return all_perms


def nextGreaterPermuation(alist):
    lst = sorted(alist)
    perms = allPossiblePermutations(lst)
    idx = perms.index(alist)
    if idx==len(perms)-1:
        return perms[0]
    else:
        return perms[idx+1]


if __name__=='__main__':
    print(nextGreaterPermuation([1, 2, 3]))
    print(nextGreaterPermuation([1, 3, 2]))
    print(nextGreaterPermuation([3, 2, 1]))
```
