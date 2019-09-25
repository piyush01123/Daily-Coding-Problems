
#include <iostream>
#include <list>

class Node{
public:
  int data;
  Node *left, *right;
};

Node *createNode(int _data){
  Node *t = new Node;
  t->data = _data;
  t->left = t->right = NULL;
  return t;
}

void BFS(Node *root){
  std::list<Node *> Q;
  if (root==NULL) return;
  Q.push_back(root);
  while (!Q.empty()){
    Node* s = Q.front();
    std::cout<<"Visited "<<s->data<<'\n';
    Q.pop_front();
    if (s->left!=NULL) Q.push_back(s->left);
    if (s->right!=NULL) Q.push_back(s->right);
  }
}

int main(){
  Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);
  BFS(root);
  return 0;
}
