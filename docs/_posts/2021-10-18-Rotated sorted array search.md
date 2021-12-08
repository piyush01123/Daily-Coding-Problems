---
layout: post
title: "Rotated sorted array search"
categories: misc
---

This problem was asked by Amazon.

An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.


My Solution(Python):
```

def binarySearch(arr, key):
    low=0
    high=len(arr)-1
    while high>=low:
        mid = (low+high)//2
        if arr[mid]>key:
            high = mid-1
        elif arr[mid]<key:
            low = mid+1
        elif arr[mid]==key:
            return mid
    return -1

def findPivot(arr):
    low=0
    high=len(arr)-1
    while high>=low:
        mid = (low+high)//2
        # print('L=', low, 'M=', mid, 'H=', high)
        if arr[mid]>arr[low] and arr[mid]<arr[high]:
            return -1
        if low==mid or high==mid:
            # print(low, high, mid, 'returning')
            return mid
        elif arr[mid]<arr[low]:
            high = mid
        elif arr[mid]>arr[high]:
            low = mid

def findIndex(arr, key):
    pivot = findPivot(arr)
    if pivot == -1:
        return binarySearch(arr, key)
    else:
        if key>arr[0]:
            return binarySearch(arr[:pivot+1], key)
        elif key<arr[0]:
            return pivot + binarySearch(arr[pivot:], key)
        else:
            return 0

if __name__=='__main__':
    A=[5, 7, 8, 10, 2, 3]
    print(findIndex(A, 2))
```
