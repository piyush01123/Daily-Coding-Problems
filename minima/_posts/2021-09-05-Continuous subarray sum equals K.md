---
layout: post
title: "Continuous subarray sum equals K"
categories: misc
---

This problem was asked by Lyft.

Given a list of integers and a number K, return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4], since 2 + 3 + 4 = 9.


My Solution(Python):
```

def contiguousSumK(A, k):
    if k==0:
        return []
    i = 0
    j = 0
    curr_sum = 0
    while j<len(A):
        while curr_sum > k:
            curr_sum -= A[i]
            i += 1
        if curr_sum == k:
            return A[i: j]
        curr_sum += A[j]
        j += 1
    return None


if __name__=='__main__':
    print(contiguousSumK([1, 2, 3, 4, 5], 9))
    print(contiguousSumK([10, 7, 4, 8, 19, 5], 11))
    print(contiguousSumK([1, 2, 3, 4, 5], 2))
```
