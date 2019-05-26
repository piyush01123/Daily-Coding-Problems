
#include <iostream>

struct node{
  int data;
  node *next;
  // node(int a){
  //   data = a;
  //   next = nullptr;
  // }
};

node *createNode(int a){
  node *temp = new node;
  temp->data = a;
  temp->next = nullptr;
  return temp;
}


class LinkedList{
private:
  node *head, *tail;
  int length;
public:
  LinkedList();
  void addNode(int);
  void printLinkedList();
  void rotate(int);
};

LinkedList::LinkedList(){
  length = 0;
}

void LinkedList::addNode(int a){
  if (length==0){
    // node A =  node(a);
    // head = tail = &A;
    head = tail = createNode(a);
  } else {
    // node A = node(a);
    // tail->next = &A;
    tail->next = createNode(a);
    tail = tail->next;
  }
  length++;
}

void LinkedList::printLinkedList(){
  node *curr = head;
  while (curr->next!=nullptr){
    std::cout<<curr->data<<"=>";
    curr = curr->next;
  }
  std::cout<<curr->data<<'\n';
}

void LinkedList::rotate(int k){
  node *curr = head;
  for (int i=0; i<k-1; i++){
    curr = curr->next;
  }
  tail->next = head;
  head = curr->next;
  curr->next = nullptr;
}


void test(){
  LinkedList l1 = LinkedList();
  l1.addNode(7);
  l1.addNode(7);
  l1.addNode(3);
  l1.addNode(5);
  l1.printLinkedList();
  l1.rotate(2);
  l1.printLinkedList();

  LinkedList l2 = LinkedList();
  l2.addNode(1);
  l2.addNode(2);
  l2.addNode(3);
  l2.addNode(4);
  l2.addNode(5);
  l2.printLinkedList();
  l2.rotate(3);
  l2.printLinkedList();
}


int main(){
  test();
  return  0;
}
