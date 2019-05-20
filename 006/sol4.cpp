
#include <iostream>

struct node{
  int data;
  node *xored;
};

node *createNode(int a){
  node *temp = new node;
  temp->data = a;
  temp->xored = NULL;
  return temp;
}

class XORLinkedList{
private:
  node *head;
  node *tail;
  int length;
public:
  XORLinkedList(){
    length = 0;
  }
  void add(int a){
    if (length==0){
      head = tail = createNode(a);
      length++;
    } else {

    }
  }

};

void test(){
  XORLinkedList ll = XORLinkedList();

}

int main(){
  test();
  return 0;
}
