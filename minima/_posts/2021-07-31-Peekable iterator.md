---
layout: post
title: "Peekable iterator"
categories: misc
---

This problem was asked by Google.

Given an iterator with methods `next()` and `hasNext()`, create a wrapper iterator, `PeekableInterface`, which also implements `peek()`. peek shows the next element that would be returned on `next()`.

Here is the interface:
```
class PeekableInterface(object):
    def __init__(self, iterator):
        pass

    def peek(self):
        pass

    def next(self):
        pass

    def hasNext(self):
        pass
```


My Solution(Python):
```


class PeekableInterface(object):
    def __init__(self, iterator):
        self.iterator = iterator
        try:
            self._nextVal = iterator.__next__()
            self._hasNextVal = True
        except StopIteration:
            self._nextVal = None
            self._hasNextVal = False

    def peek(self):
        return self._nextVal

    def next(self):
        next = self._nextVal
        try:
            self._nextVal = self.iterator.__next__()
            self._hasNextVal = True
        except StopIteration:
            next = self._nextVal= None
            self._hasNextVal = False
        return next

    def hasNext(self):
        return self._hasNextVal


def main():
    A = [3, 5, 8]
    itr = iter(A)
    p = PeekableInterface(itr)
    print(p.hasNext()) #true
    print(p.peek()) #3
    print(p.peek()) #3
    print(p.next()) #3
    print(p.hasNext()) #true
    print(p.peek()) #5
    print(p.next()) #5
    print(p.hasNext()) #true
    print(p.peek()) #8
    print(p.next()) #8
    print(p.hasNext()) #false
    print(p.peek()) #None
    print(p.next()) #None

if __name__=='__main__':
    main()
```
