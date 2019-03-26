
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


struct node{
  // Binary Tree data structure
  int data;
  node *left, *right;
};

node *createNode(int val){
  // creates binary tree node
  node *temp = new node;
  temp->data = val;
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
  }
}


vector<int> preOrderTraversal(node *root){
  // Returning the vector
  vector<int> v;
  preOrderTraversalUtil(root, v);
  return v;
}


bool isSameTree(node *root1, node *root2){
  // Returns whether two binary trees are the same
  if (root1 == NULL && root2 == NULL) return true;
  if ((root1  != NULL && root2 == NULL) || (root2 != NULL && root1 == NULL)) return false;
  if (root1->data  !=  root2->data) return false;
  return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

void insertBST(node *root, int data){
  if (root == NULL) root = createNode(data);
  if (data <= root->data){
    if (root->left == NULL){
      root->left = createNode(data);
    }else{
      insertBST(root->left, data);
    }
  }else{
    if (root->right == NULL){
      root->right = createNode(data);
    }else{
      insertBST(root->right, data);
    }
  }
}

bool isSubtree(node *s, node*t){
  // Returns whether t is a subtree of s
  return isSameTree(s, t) || isSameTree(s->left, t) || isSameTree(s->right, t);
}

int main(){
  int N = 100; // random numbers in [0, N] range
  int num;
  node *root1 = createNode(50);
  node *root2 = createNode(50);
  for (int i=0; i<10; i++){
    num = rand()%N;
    insertBST(root1, num);
    insertBST(root2, num);
  }
  node *root1_dad = createNode(rand()%N);
  root1_dad->left = createNode(rand()%N);
  root1_dad->right = root1;
  root1 = root1_dad;

  vector<int> v;
  v = preOrderTraversal(root1);
  cout << "Tree 1 Traversal" << endl;
  ostream_iterator<int> outit (cout, " \n");
  copy(v.begin(), v.end(), outit);

  v = preOrderTraversal(root2);
  cout << "Tree 2 Traversal" << endl;
  copy(v.begin(), v.end(), outit);

  cout << "Is Tree2 a subtree of tree 1" << endl;
  cout << boolalpha << isSubtree(root1, root2) << endl;
  return 0;
}
