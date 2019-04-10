
#include <iostream>
#include <vector>


struct node{
  //linked list data structure
  int data;
  node *next;
};


node *createNode(int data){
  //fn to create ll node
  node *temp = new node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}


void printLinkedList(node *head){
  //prints linked list
  std::cout << "PRINTING" << std::endl;
  while (head!=NULL){
    std::cout << head->data << std::endl;
    head = head->next;
  }
}


node *numberToLinkedList(int number){
  //converts number base 10 to linked list
  int d = number%10;
  // std::cout << d << std::endl;
  number = number/10;
  node *head = createNode(d);
  node *curr = head;
  while (number>0){
    d = number%10;
    // std::cout << d << std::endl;
    curr->next = createNode(d);
    curr = curr->next;
    number = number/10;
  }
  return head;
}


node *addNumbers(node *l1, node *l2){
  //adds two numbers expressed as ll to return sum as ll
  node *head = createNode(-1);
  node *curr = head;
  int carry = 0;
  int digit, sum;
  //while both are non-null
  while (l1!=NULL && l2!=NULL){
    sum = l1->data + l2->data + carry;
    carry = (sum>=10)?1:0;
    digit = sum%10;
    curr->next = createNode(digit);
    curr = curr->next;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1!=NULL){
    sum = l1->data + carry;
    carry = (sum>=10)?1:0;
    digit = sum%10;
    curr->next = createNode(digit);
    curr = curr->next;
    l1 = l1->next;
  }
  while (l2!=NULL){
    sum = l2->data + carry;
    carry = (sum>=10)?1:0;
    digit = sum%10;
    curr->next = createNode(digit);
    curr = curr->next;
    l2 = l2->next;
  }
  if (carry>0) curr->next = createNode(carry);
  return head->next;
}


void test(){
  //creates and runs few test cases
  node *l1 = numberToLinkedList(99);
  node *l2 = numberToLinkedList(25);
  node *l3 = addNumbers(l1, l2);
  printLinkedList(l3);

  l1 = numberToLinkedList(1918);
  l2 = numberToLinkedList(86);
  l3 = addNumbers(l1, l2);
  printLinkedList(l3);

}


int main(){
  //runs the test
  test();
  return 0;
}
