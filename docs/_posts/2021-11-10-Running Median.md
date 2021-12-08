---
layout: post
title: "Running Median"
categories: misc
---

This problem was asked by Microsoft.

Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence `[2, 1, 5, 7, 2, 0, 5]`, your algorithm should print out:

2
1.5
2
3.5
2
2
2


My Solution(Python):
```
import unittest

class runningList(list):
    # Brute force Implementation: O(N*log(N)) at each insert
    def __new__(cls):
        return super().__new__(cls)
    def __init__(self):
        super().__init__()
        self.median = None
    def insertNum(self, num):
        self.append(num)
        self.sorted = sorted(self)
        if len(self)%2==0:
            self.median = (self.sorted[len(self)//2 - 1] + self.sorted[len(self)//2])/2
        else:
            self.median = self.sorted[len(self)//2]

class testClass(unittest.TestCase):
    def testInsert(self):
        rl = runningList()
        A = [2, 1, 5, 7, 2, 0, 5]
        B = []
        for a in A:
            rl.insertNum(a)
            B.append(rl.median)
        self.assertEqual(B, [2, 1.5, 2, 3.5, 2, 2, 2])

if __name__=='__main__':
    unittest.main()
```
