
#include <iostream>
#include <algorithm>

struct node{
  int data;
  node *left, *right;
};

node *createNode(int data){
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

int maxDepth(node *root){
  // Returns the maximum depth of a binary tree
  if (root == NULL) return 0;
  return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}


void printAllKeysOfLevel(node *root, int level){
  // prints all keys of a b. tree at a level
  if (root==NULL) return;
  if (level==1){
    std::cout << root->data << " ";
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
    std::cout << "Level = " << d << std::endl;
    printAllKeysOfLevel(root, d);
    std::cout<<std::endl;
  }
}

bool hasOne(node *root){
  //utility function useful later
  if (root==NULL) return false;
  bool b1 = hasOne(root->left);
  bool b2 = hasOne(root->right);
  return root->data==1 || b1 || b2;
}

node *pruneTree(node *root){
  //prunes tree
  if (!hasOne(root)) return NULL;
  root->left = pruneTree(root->left);
  root->right = pruneTree(root->right);
  return root;
}

void test(){
  //creates a test case and runs test
  node *root = createNode(0);
  root->left = createNode(1);
  root->right = createNode(0);
  root->right->left = createNode(1);
  root->right->right = createNode(0);
  root->right->left->left = createNode(0);
  root->right->left->right = createNode(0);
  std::cout<<"\nBefore pruning\n";
  levelWisePrint(root);
  node *root2 = pruneTree(root);
  std::cout<<"\nAfter pruning\n";
  levelWisePrint(root2);
}

int main(){
  //calls fns
  test();
  return 0;
}
