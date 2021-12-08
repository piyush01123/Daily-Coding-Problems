---
layout: post
title: "Deepest Node in Binary Tree"
categories: misc
---


This problem was asked by Google.

Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.

```
    a
   / \
  b   c
 /
d
```

The solution successfully finds the deepest node and we use a [library](https://github.com/jdmcpeek/pretty-print-binary-tree) to visualize the tree:
```
__73__
/     \
40      80
     / \
   76  95

depth= 3
Deepest Node = 76
```


My Solution(C++):
```
#include <iostream>

using namespace std;

struct node{
  // B. Tree data structure
  int data;
  node *left, *right;
};


node *createNode(int val){
  // Create a b. tree node
  node *temp = new node;
  temp->data = val;
  temp->left = temp->right = NULL;
  return temp;
}


int maxDepth(node *root){
  // finds max depth of a b. tree
  if (root == NULL) return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


node *deepestNode(node *root, int depth){
  // returns the leftmost node at the max depth level
  if (depth==1) return root;
  else{
    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    if (depth_left >= depth_right)
      return deepestNode(root->left, depth-1);
    else
      return deepestNode(root->right, depth-1);
  }
}

void test(){
  // creates and runs a test case
  node *root = createNode(3);
  root->left = createNode(-3);
  root->right = createNode(7);
  root->left->left = createNode(30);
  root->left->right = createNode(50);
  root->right->left = createNode(-100);
  cout << "Depth = "  << maxDepth(root) << " and deepestNode is " << deepestNode(root, maxDepth(root))->data << endl;
}

int main(){
  // runs the test
  test();
}
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


def findDepth(root: 'TreeNode') -> int:
    if root is None:
        return 0
    else:
        return 1 + max(findDepth(root.left), findDepth(root.right))

def deepestNode(root: 'TreeNode', depth: int) -> 'RootNode':
    if depth==1:
        return root
    else:
        depth_left = findDepth(root.left)
        depth_right = findDepth(root.right)
        if depth_left >= depth_right:
            return deepestNode(root.left, depth-1)
        else:
            return deepestNode(root.right, depth-1)

def main():
    myTree = TreeNode()
    for _ in range(5):
        val = random.randint(1, 100)
        myTree.insertNode(val)
    myTree.prettyPrint()
    print('\n')
    depth = findDepth(myTree)
    print('depth=', depth)
    deepest_node = deepestNode(myTree, depth)
    print('Deepest Node = %s' %deepest_node.data)

if __name__=='__main__':
    main()
```
