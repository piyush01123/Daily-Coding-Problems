
#include <iostream>
#include <cstdint>

// struct node{
//   int data;
//   node *left, *right;
//   // node(int a){data=a; left=right=nullptr;}
// };
//
// node *createNode(int data){
//   node *temp = new node;
//   temp->data = data;
//   temp->left = temp->right = nullptr;
//   return temp;
// }

struct node{
  int data;
  node *xored;
};

node *XOR(node *n1, node *n2){
  int p1 = reinterpret_cast<uintptr_t>(n1);
  int p2 = reinterpret_cast<uintptr_t>(n2);
  int p = p1^p2;
  // std::cout<<p<<'\n';
  node *n = reinterpret_cast<node *>(p);
  return n;
}

int main(){
  node *n = new node;
  n->data = 20;
  n->xored = nullptr;
  return 0;
}
