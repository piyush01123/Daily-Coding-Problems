
#include <iostream>

struct node{
  int data;
  node *next;
  node *prev;
};

node *createNode(int a){
  node *temp = new node;
  temp->data = a;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

class LinkedList{
private:
  node *head;
  node *tail;
  int length;
public:
  LinkedList(){length = 0;} //constructor
  void addNode(int a){
    if (length==0){
      head = tail = createNode(a);
      length++;
    } else {
      tail->next = createNode(a);
      tail->next->prev = tail;
      tail = tail->next;
      length++;
    }
  }
  void printLength(){std::cout<<"Length = "<<length<<'\n';}
  void printLL(){
    node *curr = head;
    while (curr->next!=NULL){
      std::cout<<curr->data<<"-->";
      curr = curr->next;
    }
    std::cout<<curr->data<<'\n';
  }
  void printLLRev(){
    node *curr = tail;
    while (curr->prev!=NULL){
      std::cout<<curr->data<<"-->";
      curr = curr->prev;
    }
    std::cout<<curr->data<<'\n';
  }

};

void test(){
  LinkedList ll = LinkedList();
  ll.addNode(12);
  ll.addNode(23);
  ll.addNode(34);
  ll.addNode(322);
  ll.addNode(39);
  ll.printLength();
  ll.printLL();
  ll.printLLRev();
}

int main(){
  test();
  return 0;
}
