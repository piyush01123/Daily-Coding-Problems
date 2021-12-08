---
layout: post
title: "Print binary tree level-wise"
categories: misc
---

This problem was asked by Microsoft.

Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.

```
  1
 / \
2   3
   / \
  4   5
```


My Solution(C++):
```

#include <iostream>
#include <vector>

using namespace std;

struct node{
  // Binary Tree data structure
  int data;
  node *left, *right;
};


node *createNode(int val){
  // Function to create a binary tree node
  node *temp = new node;
  temp->data = val;
  temp->left = temp->right = NULL;
  return temp;
}


int maxDepth(node *root){
  // Returns the maximum depth of a binary tree
  if (root == NULL) return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


void printAllKeysOfLevel(node *root, int level){
  // prints all keys of a b. tree at a level
  if (root==NULL) return;
  if (level==1){
    cout << root->data << endl;
  }
  if (level>1){
    printAllKeysOfLevel(root->left, level-1);
    printAllKeysOfLevel(root->right, level-1);
  }
  return;
}


void levelWisePrint(node *root){
  // Prints the b. tree level wise
  int depth = maxDepth(root);
  for (int d=1; d<=depth; d++){
    cout << "Level = " << d << endl;
    printAllKeysOfLevel(root, d);
  }
}

void test(){
  // Create and run a test case
  node *root = createNode(3);
  root->left = createNode(-3);
  root->right = createNode(7);
  root->left->left = createNode(30);
  root->left->right = createNode(50);
  root->right->left = createNode(-100);
  levelWisePrint(root);
}


int main(){
  // runs the test
  test();
}
```


My Solution(Python):
```

from tree import Node


class TreeNode(Node):
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def findDepth(root):
    if root is None:
        return 0
    else:
        return 1 + max(findDepth(root.left), findDepth(root.right))


def printLevel(root, d, x):
    if x==d and root is not None:
        print(root.data)
    if x>d:
        return
    if root.left is not None:
        printLevel(root.left, d, x+1)
    if root.right is not None:
        printLevel(root.right, d, x+1)


def printTreeLevelWise(root):
    depth = findDepth(root)
    for d in range(depth):
        printLevel(root, d, x=0)


def  main():
    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(5)
    tree.prettyPrint(); print('\n')
    printTreeLevelWise(tree)

    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.left.left = TreeNode(4)
    tree.left.right = TreeNode(5)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(5)
    tree.right.left.left = TreeNode(6)
    tree.right.left.right = TreeNode(7)
    tree.right.right.left = TreeNode(8)
    tree.right.right.right = TreeNode(9)
    tree.prettyPrint(); print('\n')
    printTreeLevelWise(tree)


if __name__=='__main__':
    main()
```
