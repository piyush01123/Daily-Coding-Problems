---
layout: post
title: "Stack Implementation"
categories: misc
---

This problem was asked by Amazon.

Implement a stack that has the following methods:

- `push(val)`, which pushes an element onto the stack
- `pop()`, which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
- `max()`, which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return `null`.

Each method should run in constant time.


My Solution(Python):
```
class Stack(list):
    """
    A lot of cheating, use python's in-built lists a lot
    """
    def __init__(self):
        super().__init__()
        self.maxElement = -10**10
        self.max_ending_here = list()
    def push(self, val):
        self.append(val)
        self.maxElement = max(val, self.maxElement)
        self.max_ending_here.append(self.maxElement)
    def popStack(self):
        if self.__len__()==0:
            raise Exception("Empty Stack")
        self.pop()
        self.max_ending_here.pop()
    def max(self):
        if self.__len__()>0:
            return self.max_ending_here[-1]
        else:
            raise Exception("Empty Stack")

if __name__=='__main__':
    import random
    s = Stack()
    for _ in range(10):
        s.push(random.randint(-100, 100))
        print(s)
        print(s.max())
    for _ in range(10):
        s.popStack()
        print(s)
        print(s.max())
```
