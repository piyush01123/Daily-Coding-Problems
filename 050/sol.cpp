
#include <iostream>
#include <vector>
#include <string>

struct node{
  char data;
  node *left, *right;
};

node *createNode(char data){
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void inOrderTraversal(node *root, std::vector<char> &v){
  if (root==NULL){
    return;
  }
  v.push_back('(');
  inOrderTraversal(root->left, v);
  v.push_back(root->data);
  inOrderTraversal(root->right, v);
  v.push_back(')');
}

int evaluate(node *root){
  std::vector<char> v;
  inOrderTraversal(root, v);
  // for  (char c: v) printf("%c  ", c);
  // std::cout << std::endl;
  std::string s(v.begin(), v.end());
  std::cout << s << std::endl;
  return 0;
}

int evaluateTree(node *root){
  if (root->left==NULL and root->right==NULL){
    int data = root->data;
    return data-48;
  }
  int left_data = evaluateTree(root->left);
  int right_data = evaluateTree(root->right);
  char sign = root->data;
  switch (sign) {
    case '+': return left_data+right_data;
    case '-': return left_data-right_data;
    case '*': return left_data*right_data;
    case '/': return left_data/right_data;
  }
  return 0; //I dont like dirty warnings
}

void test(){
  node *root = createNode('*');
  root->left = createNode('+');
  root->right = createNode('+');
  root->left->left = createNode('3');
  root->left->right = createNode('2');
  root->right->left = createNode('4');
  root->right->right = createNode('5');
  // std::cout << evaluate(root) << std::endl;
  // char x = '5';
  // int y = x;
  // std::cout << x << "   " << y-48 << "      " << std::endl;
  std::cout << evaluateTree(root) << std::endl;
}

int main(){
  test();
  return 0;
}
