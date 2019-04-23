
#include <iostream>

struct Node{
  int data;
  Node *next;
};

Node *createNode(int data){
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void printLinkedList(Node *head){
  while (head->next!=NULL){
    std::cout<<head->data<<" --> ";
    head = head->next;
  }
  std::cout<<head->data<<std::endl;
}

Node *swapEveryTwo(Node *head){
  Node *curr = head;
  while (curr->next!=NULL && curr->next->next!=NULL) {
    int cache = curr->data;
    curr->data = curr->next->data;
    curr->next->data = cache;
    curr = curr->next->next;
  }
  return head;
}


void test(){
  std::cout<<"\nTest Case 1\n";
  Node *head = createNode(1);
  Node *curr = head;
  for (int i=2; i<=4; i++){
    curr->next = createNode(i);
    curr = curr->next;
  }
  std::cout<<"Original Linked List"<<std::endl;
  printLinkedList(head);
  Node *swapped = swapEveryTwo(head);
  std::cout<<"Modified Linked List"<<std::endl;
  printLinkedList(swapped);

  std::cout<<"\nTest Case 2\n";
  head = createNode(1);
  curr = head;
  for (int i=2; i<=3; i++){
    curr->next = createNode(i);
    curr = curr->next;
  }
  std::cout<<"Original Linked List"<<std::endl;
  printLinkedList(head);
  swapped = swapEveryTwo(head);
  std::cout<<"Modified Linked List"<<std::endl;
  printLinkedList(swapped);

  std::cout<<"\nTest Case 3\n";
  head = createNode(1);
  curr = head;
  for (int i=2; i<=10; i++){
    curr->next = createNode(i);
    curr = curr->next;
  }
  std::cout<<"Original Linked List"<<std::endl;
  printLinkedList(head);
  swapped = swapEveryTwo(head);
  std::cout<<"Modified Linked List"<<std::endl;
  printLinkedList(swapped);
}


int main(){
  test();
  return 0;
}
