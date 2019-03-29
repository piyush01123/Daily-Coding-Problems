
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


void preOrderTraversal(node *root, vector<int> &v){
  // we dont actually need a util to  do preorder traversal but if we want to return
  // a vector than we do.
  // This is the actual preorder traversal
  if (root != NULL){
    v.push_back(root->data);
    preOrderTraversal(root->left, v);
    preOrderTraversal(root->right, v);
  }
}


void printPreOrderTraversal(node *root){
  // Prints out the preorder traversal
  vector<int> v;
  preOrderTraversal(root, v);
  ostream_iterator<int> outit {cout, " "};
  copy(v.begin(), v.end(), outit);
  cout << endl;
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


bool isSameTree(node *root1, node *root2){
  // Returns whether two binary trees are the same
  if (root1 == NULL && root2 == NULL) return true;
  if ((root1  != NULL && root2 == NULL) || (root2 != NULL && root1 == NULL)) return false;
  if (root1->data  !=  root2->data) return false;
  return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}


bool isSubtree(node *s, node*t){
  // Returns whether t is a subtree of s
  if (s==NULL) return false;
  return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}


void test(){
  // creates and runs a test case
  int N = 100; // random numbers in [0, N] range
  int num;
  node *root1 = createNode(50);
  node *root2 = createNode(50);
  srand(1);
  for (int i=0; i<10; i++){
    num = rand()%N;
    insertBST(root1, num);
    insertBST(root2, num);
  }
  node *root1_dad = createNode(rand()%N);
  root1_dad->left = createNode(rand()%N);
  root1_dad->right = root1;
  root1 = root1_dad;


  cout << "Tree 1 Traversal" << endl;
  printPreOrderTraversal(root1);
  cout << "Tree 2 Traversal" << endl;
  printPreOrderTraversal(root2);
  cout << "Is Tree 2 a subtree of tree 1" << endl;
  cout << boolalpha << isSubtree(root1, root2) << endl;


  node *root3 = createNode(50);
  srand(2);
  for (int i=0; i<10; i++){
    insertBST(root3, rand()%N);
  }
  cout << "Tree 3 Traversal" << endl;
  printPreOrderTraversal(root3);
  cout << "Is Tree 3 a subtree of tree 1" << endl;
  cout << boolalpha << isSubtree(root1, root3) << endl;
}


int main(){
  // runs the test
  test();
}
