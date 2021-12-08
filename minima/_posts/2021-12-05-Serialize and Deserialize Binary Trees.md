---
layout: post
title: "Serialize and Deserialize Binary Trees"
categories: misc
---

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

```
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

The following test should pass:

```
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
```


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;


struct node{
  // Data structure for binary tree
  int data;
  node *left, *right;
};


node *createNode(int data){
  // Useful to create a node
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}


void preOrderTraversalUtil(node *root, vector<int> &v){
  // we dont actually need a util to  do preorder traversal but if we want to return
  // a vector than we do.
  // This is the actual preorder traversal
  if (root != NULL){
    v.push_back(root->data);
    preOrderTraversalUtil(root->left, v);
    preOrderTraversalUtil(root->right, v);
  }else{
    v.push_back(-1);
  }
}


vector<int> preOrderTraversal(node *root){
  // Returning the vector
  vector<int> v;
  preOrderTraversalUtil(root, v);
  return v;
}


string serializeTree(node *root){
  // Function to serialize the tree
  vector<int> v = preOrderTraversal(root);
  if (v.size()==0){
    return "";
  }
  stringstream res;
  ostream_iterator<int> outs(res, ",");
  copy(v.begin(), v.end(), outs);
  string result = res.str();
  result.pop_back();
  return result;
}


node *helper(list<int> &preorder){
  // Useful to deserialization
  int val;
  val = preorder.front();
  preorder.pop_front();
  if (val==-1) return NULL;
  node *root = createNode(val);
  root->left = helper(preorder);
  root->right = helper(preorder);
  return root;
}


node *deserializeTree(string serialized){
 // Function for deserialization
 stringstream ss(serialized);
 list<int> preorder;
 node *root;
 string key;
 int k, val;
 while (getline(ss, key, ',')){
   k = 0;
   stringstream(key) >> k;
   preorder.push_back(k);
 }
root = helper(preorder);
return root;
}


int main(){
  // Create and run a test case
  node *root = createNode(5);
  root->left = createNode(8);
  root->right = createNode(9);
  root->right->left = createNode(10);
  string serialized = serializeTree(root);
  cout << "Serialized Tree = " << serialized << endl;
  node *root_retrieved = deserializeTree(serialized);
  string deserialized = serializeTree(root_retrieved);
  cout << "Deserialized Tree " << deserialized << endl;
  return 0;
}
```


My Solution(Python):
```
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x=None):
        self.val = x
        self.left = None
        self.right = None

    def insertNode(self, val):
        if not self.val:
            self.val = val
        elif val <= self.val:
            if not self.left:
                self.left = TreeNode(val)
            else:
                self.left.insertNode(val)
        else:
            if not self.right:
                self.right = TreeNode(val)
            else:
                self.right.insertNode(val)

    def preOrderOrig(self, root):
        A = []
        if root is not None:
            A.append(root.val)
            A.extend(self.preOrderOrig(root.left))
            A.extend(self.preOrderOrig(root.right))
        return A

    def preOrder(self, root):
        A = []
        if root is not None:
            A.append(root.val)
            if root.left is not None:
                A.extend(self.preOrder(root.left))
            else:
                A.append(None)
            if root.right is not None:
                A.extend(self.preOrder(root.right))
            else:
                A.append(None)
            return A
        else:
            return None


    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        A =  self.preOrder(root)
        if A is None:
            return None
        return ','.join(list(map(str, A)))

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data is None:
            return None
        def helper(lst):
            first = lst.pop(0)
            if first is None:
                return None
            else:
                root = TreeNode(first)
                root.left = helper(lst)
                root.right = helper(lst)
                return root

        A = data.split(',')
        A = [int(a) if a!='None' else None for a in A ]
        return helper(A)

if __name__ == '__main__':
    import random
    myTree = TreeNode()
    for _ in range(10):
        myTree.insertNode(random.randint(1, 100))
    Tree = TreeNode()
    print('Pre-Order Traversal of tree used =', Tree.preOrderOrig(myTree))
    out = Tree.serialize(myTree)
    print('Serialized tree = ', out)
    tre = Tree.deserialize(out)
    print('Pre-Order Traversal of deserialized tree =', Tree.preOrderOrig(tre))
    print('Serialized string for the deserialized tree =', Tree.serialize(tre))
```
