---
layout: post
title: "Max of each Subarray"
categories: misc
---

This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.


My Solution(Python):
```
from collections import deque
class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(nums)==0:
            return []
        if k==0:
            return nums
        deck = deque()
        for i in range(k):
            while len(deck) != 0:
                if nums[i] > nums[deck[-1]]:
                    deck.pop()
                else:
                    break
            deck.append(i)
        res = []
        for i in range(k, len(nums)):
            # print('current Deck', deck, 'at i = ', i)
            res.append(nums[deck[0]])
            if deck[0]<i-k+1:
                # print('deck[0]<i-k+1')
                deck.popleft()
            # print('current Deck', deck, 'at i = ', i)
            while len(deck) != 0:
                # make deck such that it is either empty or nums at its last
                # element is greater than current num
                if nums[i]>nums[deck[-1]]:
                    # print('we pop at i=', i)
                    deck.pop()
                else:
                    break
            # print('current Deck', deck, 'at i = ', i)
            deck.append(i)
        res.append(nums[deck[0]])
        return res
```
