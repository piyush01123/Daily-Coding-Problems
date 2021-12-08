---
layout: post
title: "All paths in a binary tree"
categories: misc
---

This problem was asked by Facebook.

Given a binary tree, return all paths from the root to leaves.

For example, given the tree:
```
   1
  / \
 2   3
    / \
   4   5
```
Return `[[1, 2], [1, 3, 4], [1, 3, 5]]`.


My Solution(Python):
```

from tree import Node

class TreeNode(Node):
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def allPaths(root, paths, path):
    if root is None:
        return False
    path.append(root.data)
    if root.left is None and root.right is None:
        paths.append(path)
        return True
    pathc1 = path.copy()
    pathc2 = path.copy()
    if root.left is not None:
        allPaths(root.left, paths, pathc1)
    if root.right is not None:
        allPaths(root.right, paths, pathc2)



if __name__=='__main__':
    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(5)
    tree.prettyPrint(); print('\n')
    paths = []
    path = []
    allPaths(tree, paths, path)
    print(paths)
```
