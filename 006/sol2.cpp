
#include <iostream>

struct node{
  int data;
  node *next;
};

node *createNode(int a){
  node *temp = new node;
  temp->data = a;
  temp->next = NULL;
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
}

int main(){
  test();
  return 0;
}
