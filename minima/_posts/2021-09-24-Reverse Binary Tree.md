---
layout: post
title: "Reverse Binary Tree"
categories: misc
---


This problem was asked by Google.

Invert a binary tree.

For example, given the following tree:
```
    a
   / \
  b   c
 / \  /
d   e f
```
should become:
```
  a
 / \
 c  b
 \  / \
  f e  d
```

Our solution is able to achieve this:
```
______57______
/             \
__16__          __72__
/     \         /     \
16      20      69      90
/         \             /  
7          52          76     



______57______
/             \
__72__          __16__
/     \         /     \
90      69      20      16
\             /         \
76          52           7 
```


My Solution(Python):
```

from tree import Node
import random

class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)

    def insertNode(self, val):
        if self.data is None:
            self.data = val
        elif val<=self.data:
            if self.left is None:
                self.left = TreeNode(val)
            else:
                self.left.insertNode(val)
        else:
            if self.right is None:
                self.right = TreeNode(val)
            else:
                self.right.insertNode(val)

def reverseTree(root):
    if root is None:
        return None
    root.left, root.right = reverseTree(root.right), reverseTree(root.left)
    return root

def main():
    myTree = TreeNode()
    for _ in range(10):
        val = random.randint(1, 100)
        myTree.insertNode(val)
    myTree.prettyPrint()
    print('\n\n\n')
    rev_tree = reverseTree(myTree)
    rev_tree.prettyPrint()
    print('\n')

if __name__=='__main__':
    main()
```
