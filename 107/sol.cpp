
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
