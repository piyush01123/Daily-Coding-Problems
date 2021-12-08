---
layout: post
title: "Binary Tree Locking"
categories: misc
---

This problem was asked by Google.

Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

`is_locked`, which returns whether the node is locked
`lock`, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return `true`.
`unlock`, which unlocks the node. If it cannot be unlocked, then it should return `false`. Otherwise, it should unlock it and return `true`.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.


My Solution(Python):
```

from tree import Node
import random

class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)
        self._lock_state = False

    def insertNode(self, val):
        if self.left is None and self.right is not None:
            self.left = TreeNode(val)
            self.left.parent = self
        elif self.right is None and self.left is not None:
            self.right = TreeNode(val)
            self.right.parent = self
        elif self.left is None and self.right is None:
            choice = random.choice(['LEFT', 'RIGHT'])
            if choice=='LEFT':
                self.left = TreeNode(val)
                self.left.parent = self
            else:
                self.right = TreeNode(val)
                self.right.parent = self
        elif self.left is not None and self.right is not None:
            choice = random.choice(['LEFT', 'RIGHT'])
            if choice=='LEFT':
                self.left.insertNode(val)
            else:
                self.right.insertNode(val)

    def lock(self):
        if self.parent._lock_state or self.left._lock_state or self.right._lock_state:
            return False, 'Not possible'
        self._lock_state = True
        return True

    def unlock(self):
        if self.parent._lock_state or self.left._lock_state or self.right._lock_state:
            return False, 'Not possible'
        self._lock_state = False
        return True

    def is_locked(self):
        return self._lock_state

if __name__=='__main__':
    tree = TreeNode('*')
    for _ in range(20):
        val = random.randint(1, 100)
        tree.insertNode(val)
    tree.prettyPrint()
    print('\n\n\n')
    print(tree.left.lock()) #should lock and returnn true
    print(tree.is_locked()) #should be false
    print(tree.left.is_locked()) #should be true
    print(tree.left.left.is_locked()) #should be false
    print(tree.left.left.unlock()) #should not be possible
    print(tree.left.unlock()) #should be possible
    print(tree.left.left.is_locked()) #should be false
```
