---
layout: post
title: "Lexicographic matrix sort"
categories: misc
---

This problem was asked by Google.

You are given an N by M 2D matrix of lowercase letters. Determine the minimum number of columns that can be removed to ensure that each row is ordered from top to bottom lexicographically. That is, the letter at each column is lexicographically later as you go down each row. It does not matter whether each row itself is ordered lexicographically.

For example, given the following table:
```
cba
daf
ghi
```
This is not ordered because of the a in the center. We can remove the second column to make it ordered:

```
ca
df
gi
```
So your function should return 1, since we only needed to remove 1 column.

As another example, given the following table:

```
abcdef
```
Your function should return 0, since the rows are already ordered (there's only one row).

As another example, given the following table:

```
zyx
wvu
tsr
```
Your function should return 3, since we would need to remove all the columns to order it.


My Solution(Python):
```

def countSorted(A: list) -> int:
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    H = {alphabet[i]: i for i in range(26)}
    N = len(A)
    M = len(A[0])
    count=0
    for i in range(M):
        lst = [H[a[i]] for a  in A]
        if lst==sorted(lst):
            count+=1
    return M-count


A = ['cba', 'daf', 'ghi']
print(countSorted(A))
A = ['abcdef']
print(countSorted(A))
A = ['zyx', 'wvu', 'tsr']
print(countSorted(A))
```
