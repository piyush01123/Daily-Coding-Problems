---
layout: post
title: "Random element from large input stream"
categories: misc
---

This problem was asked by Facebook.

Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.


My Solution(Python):
```
import unittest
import numpy as np

class Stream(list):
    """
    Even though we are inheriting a list class, we are always keeping the list
    empty. This is because the numbers are supposed to be huge. This could be slightly
    modified to store the last m elements; in case maximum m numbers are storable.
    This implementation will be similar to the Order Log example.
    """
    def __new__(cls):
        return super().__new__(cls)
    def __init__(self):
        super().__init__()
        self.length = 0
    def insertNum(self, num):
        """
        Inserts a number and updates currentRandom with the old random number
        with probability (N-1)/N and new number with probability 1/N
        """
        self.length += 1
        N = self.length
        if N==1:
            self.currentRandom = num
        else:
            nums = [self.currentRandom, num]
            probs = [(N-1)/N,  1/N]
            sel_idx = int(np.random.choice(2, 1, p=probs))
            self.currentRandom = nums[sel_idx]


class testClass(unittest.TestCase):
    def testFirstInsert(self):
        stream = Stream()
        num = np.random.randint(10**10, 10**11)
        stream.insertNum(num)
        self.assertEqual(stream.currentRandom, num)
    def testMoreInserts(self):
        stream = Stream()
        for _ in range(10):
            stream.insertNum(np.random.randint(10**10, 10**11))
        self.assertTrue(isinstance(stream.currentRandom, int))

if __name__=='__main__':
    unittest.main()
```
