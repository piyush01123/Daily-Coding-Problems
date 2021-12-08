---
layout: post
title: "Queue Implementation"
categories: misc
---

This problem was asked by Apple.

Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.


My Solution(Python):
```

class Queue(list):
    def __init__(self):
        super().__init__()

    def enqueue(self, element):
        self.append(element)

    def dequeue(self):
        return self.pop(0)


def main():
    queue = Queue()
    queue.enqueue(7)
    queue.enqueue(9)
    queue.enqueue(10)
    out = queue.dequeue()
    print(out, queue)


if __name__=='__main__':
    main()
```
