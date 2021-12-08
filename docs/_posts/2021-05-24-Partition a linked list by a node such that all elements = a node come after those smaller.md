---
layout: post
title: "Partition a linked list by a node such that all elements = a node come after those smaller"
categories: misc
---

This problem was asked by LinkedIn.

Given a linked list of numbers and a pivot k, partition the linked list so that all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list `5 -> 1 -> 8 -> 0 -> 3` and k = 3, the solution could be `1 -> 0 -> 5 -> 8 -> 3`.


My Solution(C++):
```


#include <iostream>
#include <vector>

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
  void partition(int);
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

void LinkedList::partition(int k){
  std::vector<int> dropped; //dropped elements which are >= k
  node *curr = head;
  while (curr!=nullptr && curr->data>=k){
    dropped.push_back(curr->data);
    curr = curr->next;
  }
  head = curr;
  node *curr2;
  while (curr != nullptr){
    curr2 = curr->next;
    while (curr2!=nullptr && curr2->data>=k){
      dropped.push_back(curr2->data);
      curr2 = curr2->next;
    }
    curr->next = curr2;
    curr = curr->next;
  }

  // std::cout<<std::boolalpha<<(curr==nullptr)<<'\n';
  // for (int n: dropped) std::cout<<n<<',';
  // curr = createNode(dropped[0]);

  // for (int n: dropped){
  //   curr = createNode(n);
  //   curr = curr->next;
  // }
  curr = head;
  while (curr->next!=nullptr) curr = curr->next;
  // std::cout<<std::boolalpha<<(curr==nullptr)<<'\n';
  for (int n: dropped){
    curr->next = createNode(n);
    tail = curr;
    curr = curr->next;
  }
}


void test(){
  LinkedList l1 = LinkedList();
  l1.addNode(5);
  l1.addNode(1);
  l1.addNode(8);
  l1.addNode(0);
  l1.addNode(3);
  l1.printLinkedList();
  l1.partition(3);
  l1.printLinkedList();
}


int main(){
  test();
  return  0;
}
```
