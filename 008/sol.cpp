
#include <iostream>

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


bool isUnivalTreeUtil(node *root, int data){
  if (root==nullptr){
    return true;
  }

  if (root->data==data){
    return isUnivalTreeUtil(root->left, data) && isUnivalTreeUtil(root->right, data);
  }
  return false;
}


bool isUnivalTree(node *root){
  return isUnivalTreeUtil(root, root->data);
}


int countUnivalTree(node *root){
  if (root==nullptr){
    return 0;
  }
  int ctr1 = countUnivalTree(root->left);
  int ctr2 = countUnivalTree(root->right);
  if (isUnivalTree(root)){
    return 1+ctr1+ctr2;
  } else {
    return ctr1 + ctr2;
  }
}


void test(){

  node *root;
  root = createNode(0);
  root->left = createNode(1);
  root->right = createNode(0);
  root->right->left = createNode(1);
  root->right->right = createNode(0);
  root->right->left->left = createNode(1);
  root->right->left->right = createNode(1);
  std::cout<<countUnivalTree(root)<<'\n';

  root = createNode(5);
  root->left = createNode(5);
  root->right = createNode(5);
  root->left->left = createNode(6);
  root->left->right = createNode(8);
  root->right->left = createNode(9);
  root->right->right = createNode(7);
  std::cout<<countUnivalTree(root)<<'\n';

}


int main(){
  test();
  return 0;
}
