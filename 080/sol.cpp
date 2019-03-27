#include <iostream>

using namespace std;

struct node{
  // B. Tree data structure
  int data;
  node *left, *right;
};


node *createNode(int val){
  // Create a b. tree node
  node *temp = new node;
  temp->data = val;
  temp->left = temp->right = NULL;
  return temp;
}


int maxDepth(node *root){
  // finds max depth of a b. tree
  if (root == NULL) return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


node *deepestNode(node *root, int depth){
  // returns the leftmost node at the max depth level
  if (depth==1) return root;
  else{
    int depth_left = maxDepth(root->left);
    int depth_right = maxDepth(root->right);
    if (depth_left >= depth_right)
      return deepestNode(root->left, depth-1);
    else
      return deepestNode(root->right, depth-1);
  }
}

void test(){
  // creates and runs a test case
  node *root = createNode(3);
  root->left = createNode(-3);
  root->right = createNode(7);
  root->left->left = createNode(30);
  root->left->right = createNode(50);
  root->right->left = createNode(-100);
  cout << "Depth = "  << maxDepth(root) << " and deepestNode is " << deepestNode(root, maxDepth(root))->data << endl;
}

int main(){
  // runs the test
  test();
}
