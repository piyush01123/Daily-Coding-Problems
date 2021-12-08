---
layout: post
title: "Sort a linked list"
categories: misc
---

This problem was asked by Google.

Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list `4 -> 1 -> -3 -> 99` should become `-3 -> 1 -> 4 -> 99`.


My Solution(C++):
```

/*
MergeSort on linked list
*/

#include <iostream>

struct node{
  int data;
  node *next;
};


node *createNode(int data){
  node *temp = new node;
  temp->data = data;
  temp->next = nullptr;
  return temp;
}


class LinkedList{
private:
  int length;
  node *head;
  node *tail;

public:
  LinkedList();
  void addNode(int);
  int getNode(int);
  int getLength();
  void printLinkedList();
  LinkedList getSubLinkedList(int, int);
  LinkedList merge(LinkedList, LinkedList);
  LinkedList mergeSort();
};


LinkedList::LinkedList(){
  length = 0;
}


void LinkedList::addNode(int a){
  if (length==0){
    head = tail = createNode(a);
  } else {
    tail->next = createNode(a);
    tail = tail->next;
  }
  length++;
}


int LinkedList::getLength(){
  return length;
}


int LinkedList::getNode(int n){
  //gets node n starting from head; 0-indexed
  if (n<0 || n>=length){
    std::cout<<"n>length bad request\n";
    return -1;
  }
  node *curr = head;
  while(n>0){
    curr = curr->next;
    n--;
  }
  return curr->data;
}


void LinkedList::printLinkedList(){
  node *curr = head;
  while (curr->next!=nullptr){
    std::cout<<curr->data<<" => ";
    curr = curr->next;
  }
  std::cout<<curr->data<<'\n';
}


LinkedList LinkedList::getSubLinkedList(int i, int j){
  // returns sub-linked list from node i to node j
  // so getSubLinkedList(0, 4) returns 0->1->2->3
  // doesnt do any checks
  // use cautiously
  LinkedList l;
  int k = 0;
  node *curr = head;
  while (k<i){
    curr = curr->next;
    k++;
  }
  node *head = curr;
  while (k<j){
    l.addNode(curr->data);
    curr = curr->next;
    k++;
  }
  return l;
}


void testLinkedList(){
  std::cout << "Linked List basic tests"<<'\n';
  LinkedList ll = LinkedList();
  ll.addNode(4);
  ll.addNode(8);
  ll.addNode(7);
  ll.addNode(5);
  ll.addNode(3);
  ll.printLinkedList();
  // for (int i=-1; i<7; i++){
  //   std::cout<<"I = "<<i<<'\n';
  //   std::cout<<ll.getNode(i)<<'\n';
  // }
  LinkedList l = ll.getSubLinkedList(1, 4);
  l.printLinkedList();
}


// node *merge(node *head1, node *head2){
//   node *head = new node;
//   node *curr = head;
//   node *curr1 = head1;
//   node *curr2 = head2;
//   while (curr1!=nullptr && curr2!=nullptr){
//     if (curr1->data < curr2->data){
//       curr->next = createNode(curr1->data);
//       curr1 = curr1->next;
//     } else {
//       curr->next = createNode(curr2->data);
//       curr2 = curr2->next;
//     }
//     curr = curr->next;
//   }
//   while (curr1!=nullptr){
//     curr->next = createNode(curr1->data);
//     curr1 = curr1->next;
//     curr = curr->next;
//   }
//   while (curr2!=nullptr){
//     curr->next = createNode(curr2->data);
//     curr2 = curr2->next;
//     curr = curr->next;
//   }
//   return head->next;
// }


LinkedList LinkedList::merge(LinkedList l1, LinkedList l2){
  LinkedList l = LinkedList();
  int len1 = l1.getLength();
  int len2 = l2.getLength();
  int i, j;
  int val1, val2;
  // while (i<len1 && j<len2){
  //   val1 = l1.getNode(i);
  //   val2 = l2.getNode(j);
  //   if (val1<val2){
  //     l.addNode(val1);
  //     i++;
  //   } else {
  //     l.addNode(val2);
  //     j++;
  //   }
  // }
  // while (i<len1){
  //   val1 = l1.getNode(i);
  //   l.addNode(val1);
  //   i++;
  // }
  // while (j<len2){
  //   val2 = l.getNode(j);
  //   l.addNode(val2);
  //   j++;
  // }

  // std::cout<<"inside -- merge"<<'\n';
  // std::cout<<"L1 "<<len1<<'\n';
  // l1.printLinkedList();
  // std::cout<<"L2 "<<len2<<'\n';
  // l2.printLinkedList();

  i = j = 0;
  while (i<len1 && j<len2){
    if (l1.getNode(i)<l2.getNode(j)){
      l.addNode(l1.getNode(i++));
    } else {
      l.addNode(l2.getNode(j++));
    }
  }
  while (i<len1){
    l.addNode(l1.getNode(i++));
  }
  while (j<len2){
    l.addNode(l2.getNode(j++));
  }
  // std::cout<<"inside -- merge -- returning ll of len "<<l.getLength()<<'\n';
  // l.printLinkedList();
  return l;
}

LinkedList LinkedList::mergeSort(){
  // int len = L.getLength();
  if (length==1){
    return *this;
  }

  LinkedList l1 = getSubLinkedList(0,length/2);
  LinkedList l2 = getSubLinkedList(length/2, length);

  // std::cout<<"inmergesort"<<'\n';
  // l1.printLinkedList();
  // l2.printLinkedList();

  LinkedList l1_sorted = l1.mergeSort();
  LinkedList l2_sorted = l2.mergeSort();

  LinkedList L_sorted = merge(l1_sorted,l2_sorted);
  return L_sorted;
}


void test(){
  std::cout << "Linked List MergeSort Test"<<'\n';
  LinkedList l = LinkedList();
  l.addNode(4);
  l.addNode(1);
  l.addNode(-3);
  l.addNode(99);

  std::cout<<"Original Linked List"<<'\n';
  l.printLinkedList();
  LinkedList l_sorted = l.mergeSort();
  std::cout<<"Sorted Linked List"<<'\n';
  l_sorted.printLinkedList();

  // LinkedList l = LinkedList();
  // l.addNode(2);
  // l.mergeSort();
  // l.printLinkedList();
}

int main(){
  testLinkedList();
  test();
  return 0;
}
```
