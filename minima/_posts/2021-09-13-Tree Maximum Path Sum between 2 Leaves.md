---
layout: post
title: "Tree Maximum Path Sum between 2 Leaves"
categories: misc
---

This problem was asked by Google.

Given a binary tree of integers, find the maximum path sum between two nodes. The path must go through at least one node, and does not need to go through the root.


My Solution(Python):
```

from tree import Node
import random


class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)

    def insert_node(self, val):
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
                self.left.insert_node(val)
            else:
                self.right.insert_node(val)


def max_path_sum_util(root, res):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return root.data
    l_sum = max_path_sum_util(root.left, res)
    r_sum = max_path_sum_util(root.right, res)
    if root.left is not None and root.right is not None:
        res[0] = max(res[0], l_sum + r_sum + root.data)
        return max(l_sum, r_sum) + root.data
    elif root.left is not None and root.right is None:
        return l_sum + root.data
    elif root.left is None and root.right is not None:
        return r_sum + root.data


def maxPathSum(root):
    res = [-10**10]
    max_path_sum_util(root, res)
    return res[0]


if __name__=='__main__':
    tree = TreeNode(50)
    for _ in range(5):
        val = random.randint(-50, 50)
        tree.insert_node(val)
    tree.prettyPrint(); print('\n\n')
    print(maxPathSum(tree))
```
