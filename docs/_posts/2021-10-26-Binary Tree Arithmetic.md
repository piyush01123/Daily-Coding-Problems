---
layout: post
title: "Binary Tree Arithmetic"
categories: misc
---

This problem was asked by Microsoft.

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:
```
    *
   / \
  +    +
 / \  / \
3  2  4  5
```
You should return 45, as it is (3 + 2) * (4 + 5).


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <string>

struct node{
  char data;
  node *left, *right;
};

node *createNode(char data){
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void inOrderTraversal(node *root, std::vector<char> &v){
  if (root==NULL){
    return;
  }
  v.push_back('(');
  inOrderTraversal(root->left, v);
  v.push_back(root->data);
  inOrderTraversal(root->right, v);
  v.push_back(')');
}

int evaluate(node *root){
  std::vector<char> v;
  inOrderTraversal(root, v);
  // for  (char c: v) printf("%c  ", c);
  // std::cout << std::endl;
  std::string s(v.begin(), v.end());
  std::cout << s << std::endl;
  return 0;
}

int evaluateTree(node *root){
  if (root->left==NULL and root->right==NULL){
    int data = root->data;
    return data-48;
  }
  int left_data = evaluateTree(root->left);
  int right_data = evaluateTree(root->right);
  char sign = root->data;
  switch (sign) {
    case '+': return left_data+right_data;
    case '-': return left_data-right_data;
    case '*': return left_data*right_data;
    case '/': return left_data/right_data;
  }
  return 0; //I dont like dirty warnings
}

void test(){
  node *root = createNode('*');
  root->left = createNode('+');
  root->right = createNode('+');
  root->left->left = createNode('3');
  root->left->right = createNode('2');
  root->right->left = createNode('4');
  root->right->right = createNode('5');
  // std::cout << evaluate(root) << std::endl;
  // char x = '5';
  // int y = x;
  // std::cout << x << "   " << y-48 << "      " << std::endl;
  std::cout << evaluateTree(root) << std::endl;
}

int main(){
  test();
  return 0;
}
```


My Solution(Python):
```

class Node:
    def __init__(self, val=None):
        self.val = val
        self.left = None
        self.right = None

    def inOrderTraversal(self):
        A = []
        if self is not None:
            if self.left is not None:
                A.extend(self.left.inOrderTraversal())
            A.append(self.val)
            if self.right is not None:
                A.extend(self.right.inOrderTraversal())
        return A

    def modInOrderTraversal(self):
        A = []
        if self is not None:
            if self.left is not None:
                A.append('(')
                A.extend(self.left.modInOrderTraversal())
                A.append(')')
            A.append(self.val)
            if self.right is not None:
                A.append('(')
                A.extend(self.right.modInOrderTraversal())
                A.append(')')
        return A

    def evaluate(self):
        A = self.modInOrderTraversal()
        A = list(map(str, A))
        expression = ''.join(A)
        print(expression)
        return eval(expression)

if __name__=='__main__':
    tree = Node('*')
    tree.left = Node('+')
    tree.right = Node('+')
    tree.left.left = Node(3)
    tree.left.right = Node(2)
    tree.right.left = Node(4)
    tree.right.right = Node(5)
    # tree.right.right = Node('-')
    # tree.right.right.left = Node(5)
    # tree.right.right.right = Node(7)
    value = tree.evaluate()
    print(value)
```
