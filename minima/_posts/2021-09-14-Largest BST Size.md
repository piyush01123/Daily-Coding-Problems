---
layout: post
title: "Largest BST Size"
categories: misc
---

This problem was asked by Apple.

Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.


My Solution(Python):
```


from tree import Node
import random


class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)

    def insert_node_rnd(self, val):
        if self.left is None and self.right is not None:
            self.left = TreeNode(val)
        elif self.right is None and self.left is not None:
            self.right = TreeNode(val)
        elif self.left is None and self.right is None:
            choice = random.choice(['LEFT', 'RIGHT'])
            if choice=='LEFT':
                self.left = TreeNode(val)
            else:
                self.right = TreeNode(val)
        elif self.left is not None and self.right is not None:
            choice = random.choice(['LEFT', 'RIGHT'])
            if choice=='LEFT':
                self.left.insert_node_rnd(val)
            else:
                self.right.insert_node_rnd(val)

    def insert_node_bal(self, val):
        if not self.data:
            self.data = val
        elif val <= self.data:
            if not self.left:
                self.left = TreeNode(val)
            else:
                self.left.insert_node_bal(val)
        else:
            if not self.right:
                self.right = TreeNode(val)
            else:
                self.right.insert_node_bal(val)


def isValidBST(root):
    if root is None:
        return True
    if root.left is not None:
        c1 = root.left.data<=root.data
    else:
        c1 = True
    if root.right is not None:
        c2 = root.right.data>=root.data
    else:
        c2 = True
    return c1 and c2 and isValidBST(root.left) and isValidBST(root.right)


def largestBSTSize(root):
    if root.left is None and root.right is None:
        return 1
    elif root.left is not None and root.right is None:
        if isValidBST(root.left):
            return 1+largestBSTSize(root.left)
        else:
            return largestBSTSize(root.left)
    elif root.right is not None and root.left is None:
        if isValidBST(root.right):
            return 1+largestBSTSize(root.right)
        else:
            return largestBSTSize(root.right)
    elif root.left is not None and root.right is not None:
        if isValidBST(root):
            return 1+largestBSTSize(root.left)+largestBSTSize(root.right)
        else:
            return max(largestBSTSize(root.right), largestBSTSize(root.right))


if __name__=='__main__':
    tree = TreeNode(50)
    for _ in range(8):
        val = random.randint(1, 100)
        tree.insert_node_rnd(val)
    tree.prettyPrint(); print('\n\n')
    print(largestBSTSize(tree))

    tree = TreeNode(50)
    for _ in range(8):
        val = random.randint(1, 100)
        tree.insert_node_bal(val)
    tree.prettyPrint(); print('\n\n')
    print(largestBSTSize(tree))
```
