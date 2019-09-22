
// A better question is to convert Sorted linked list to balanced BST because
// then you cant just access any element, hence the complexity of this approach
// becomes NlogN. So, we need to traverse the LL with simultaneously creating nodes
// I have solved that problem in extras folder

#include <iostream>
#include <list>

struct TreeNode{
  int data;
  TreeNode *left, *right;
};

TreeNode *createTreeNode(int _data){
  TreeNode *temp = new TreeNode;
  temp->data = _data;
  temp->left = temp->right = NULL;
}

// log(N) solution
TreeNode *arrayToBalancedBST(int A[], int n){
  if (n<=0) return NULL;
  int B[n/2], C[n/2];
  for (int i=0; i<n/2; i++) B[i]=A[i];
  for (int i=0; i<n/2; i++) C[i] = A[i+n/2+1];
  TreeNode *root = createTreeNode(A[n/2]);
  root->left = arrayToBalancedBST(B, n/2);
  root->right = arrayToBalancedBST(C, n/2);
  return root;
}

void levelWiseTraversal(TreeNode *root){
  if (root==NULL) return;
  std::list<TreeNode *>Q;
  Q.push_back(root);
  TreeNode *n;
  while (!Q.empty()){
    n = Q.front();
    Q.pop_front();
    std::cout<<n->data<<' ';
    if (n->left) Q.push_back(n->left);
    if (n->right) Q.push_back(n->right);
  }
  std::cout<<'\n';
}

int main(){
  int A[7] = {1,2,3,4,5,6,7};
  TreeNode *root = arrayToBalancedBST(A, 7);
  levelWiseTraversal(root);
  return 0;
}
