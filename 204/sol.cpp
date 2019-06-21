
#include <iostream>
#include <algorithm>
#include <math.h>

struct node{
  int data;
  node *left, *right;
};

node *createNode(int data){
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = nullptr;
  return temp;
}

int getDepth(node *root){
  // returns depth of a node below it.
  if (root==nullptr){
    return 0;
  }
  return 1 + std::max(getDepth(root->left), getDepth(root->right));
}

void getNumKeysOfLevel(node *root, int level, int &numKeys){
  //stores the number of keys at a level in numKeys variable
  // std::cout<<"level "<<level<<'\n';
  if (level==0 && root!=nullptr){
    numKeys++;
    return;
  }
  if (level>0){
    getNumKeysOfLevel(root->left, level-1, numKeys);
    getNumKeysOfLevel(root->right, level-1, numKeys);
  }
}

int getNumKeys(node *root){
  // returns number of keys in a complete tree
  int depth = getDepth(root), numKeys = 0;
  getNumKeysOfLevel(root, depth-1, numKeys);
  return pow(2, depth-1)-1 + numKeys;
}

void test(){
  node *root = createNode(5);
  root->left = createNode(7);
  root->right = createNode(8);
  root->left->left = createNode(6);
  root->left->right = createNode(9);
  std::cout<<getNumKeys(root)<<'\n';
}

int main(){
  test();
  return 0;
}
