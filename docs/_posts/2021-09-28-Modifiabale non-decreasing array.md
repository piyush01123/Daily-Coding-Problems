---
layout: post
title: "Modifiabale non-decreasing array"
categories: misc
---

This problem was asked by Facebook.

Given an array of integers, write a function to determine whether the array could become non-decreasing by modifying at most 1 element.

For example, given the array [10, 5, 7], you should return true, since we can modify the 10 into a 1 to make the array non-decreasing.

Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a non-decreasing array.


My Solution(Python):
```

def modNonDecreasing(arr: list) -> bool:
    count = 0
    for i in range(1, len(arr)):
        if arr[i]<arr[i-1]:
            count+=1
            if count>1:
                return False
    return True

print(modNonDecreasing([10, 5, 7]))
print(modNonDecreasing([10, 5, 1]))
```
