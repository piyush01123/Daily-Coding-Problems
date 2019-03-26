
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


struct node{
  // Binary tree data structure
  int data;
  node *left, *right;
};


node *createNode(int data){
  // create a binary tree node
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}


node *insertBST(node *root, int data){
  // insert a key as so that the tree remains BST
  if (root == NULL) return createNode(data);
  if (data <= root->data)
    root->left = insertBST(root->left, data);
  else
    root->right = insertBST(root->right, data);
  return root;
}


void preOrderTraversal(node *root, vector<int> &v){
  // preOrder Traversal
  if (root != NULL){
    v.push_back(root->data);
    preOrderTraversal(root->left, v);
    preOrderTraversal(root->right, v);
  }
}


node *generate(){
  // The actual solution, size limited to 1000
  int size = rand()%1000;
  node *root = NULL;
  for (int i=0; i<size; i++){
    root = insertBST(root, rand());
  }
  return root;
}

node *generate_o1(){
  // generates binary tree of arbitrary size and shape in constant time
  node *root = createNode(0);
  if (rand()%2==1)
    root->left = NULL;
  else
    root->left = generate_o1();
  if (rand()%2==0)
    root->right = NULL;
  else
    root->right = generate_o1();
  return root;
}

int main(){
  // Run a test case
  vector<int> v;
  node *root = generate();
  preOrderTraversal(root, v);
  ostream_iterator<int> outit (cout, "\n");
  copy(v.begin(), v.end(), outit);

  root = generate_o1();
  v = {};
  preOrderTraversal(root, v);
  copy(v.begin(), v.end(), outit);

  return 0;
}
