---
layout: post
title: "LCA of Binary Tree"
categories: misc
---

This problem was asked by Twitter.

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. Assume that each node in the tree also has a pointer to its parent.

According to the definition of [LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”


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


bool findPath(node *root, node *node_to_find, vector<node> &path){
  // Builds a vector of nodes from root to node_to_find
  if (root==NULL)
    return false;
  path.push_back(*root);
  if (root==node_to_find)
    return true;
  if ((root->left!=NULL && findPath(root->left,  node_to_find, path)) || \
     (root->right!=NULL && findPath(root->right,  node_to_find, path)))
        return true;
  path.pop_back();
  return false;
}


int findLCA(node *root, node *v, node *w){
  // Returns LCA of nodes v and w in a b. tree rooted under root
  vector<node> path_v,  path_w;
  findPath(root, v, path_v);
  findPath(root, w, path_w);
  int i = 0;
  while (i<path_v.size()){
    if (path_v[i].data != path_w[i].data) break;
    i++;
  }
  return path_v[i-1].data;
}


void test(){
  // Create and run a test case
  node *root = createNode(1);
  node *l = root->left = createNode(2);
  node *r = root->right = createNode(3);
  node *ll = root->left->left = createNode(4);
  node *lr = root->left->right = createNode(5);
  node *rl = root->right->left = createNode(6);
  node *rr = root->right->right = createNode(7);
  // vector<node> path;
  // findPath(root, rl, path);
  // for (int i=0; i<path.size(); i++){
  //   cout << path[i].data << endl;
  // }

  int lca = findLCA(root, rl, rr);
  cout << "V = " << rl->data << " W = " << rr->data << " LCA = " << lca << endl;

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
    """
    Binary Tree data structure with inheritance from a vis lib with custom
    methods
    """
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def findPath(root, node, path):
    """
    Modifies path argument to store path from root to node
    """
    if root is None:
        return False
    path.append(root)
    if root==node:
        return True
    if (root.left is not None and findPath(root.left, node, path)) or   (root.right is not None and findPath(root.right, node, path)):
        return True
    path.pop()
    return False


def findLCA(root: TreeNode, v: TreeNode, w: TreeNode) -> TreeNode:
    """
    Finds LCA of nodes v and w for a tree with root 'root'
    """
    path_v = []
    path_w = []
    findPath(root, v, path_v)
    findPath(root, w, path_w)
    i = 0
    while i<min(len(path_v), len(path_w)):
        if path_v[i] != path_w[i]:
            break
        i+=1
    return path_v[i-1]


def main():
    """
    Builds a test case and runs test for LCA
    """
    root = TreeNode(1)
    l = root.left = TreeNode(2)
    r = root.right = TreeNode(3)
    ll = root.left.left = TreeNode(4)
    lr = root.left.right = TreeNode(5)
    rl = root.right.left = TreeNode(6)
    rr = root.right.right = TreeNode(7)
    root.prettyPrint(); print('\n')
    for v, w in [(ll, lr), (ll, rl), (r, ll), (l, ll)]:
        lca = findLCA(root, v, w)
        print('v=%s, w=%s, lca=%s' %(v.data, w.data, lca.data))


if __name__=='__main__':
    main()
```
