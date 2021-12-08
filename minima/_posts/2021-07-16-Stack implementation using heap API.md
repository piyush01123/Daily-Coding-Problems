---
layout: post
title: "Stack implementation using heap API"
categories: misc
---

This problem was asked by Amazon.

Implement a stack API using only a heap. A stack implements the following methods:

- `push(item)`, which adds an element to the stack
- `pop()`, which removes and returns the most recently added element (or throws an error if there is nothing on the stack)

Recall that a heap has the following operations:

- `push(item)`, which adds a new key to the heap
- `pop()`, which removes and returns the max value of the heap


My Solution(C++):
```

#include <queue>
#include <iostream>

class Stack{
private:
  std::priority_queue<std::pair<int, int>> H;
  int idx;
public:
  Stack();
  void push(int);
  int pop();
};

Stack::Stack(){
  idx = 0;
}

void Stack::push(int item){
  H.push(std::make_pair(idx, item));
  idx++;
}

int Stack::pop(){
  std::pair<int, int> top = H.top();
  H.pop();
  idx--;
  return top.second;
}

void test(){
  Stack S = Stack();
  S.push(5);
  S.push(3);
  S.push(6);
  std::cout<<S.pop()<<'\n';
  S.push(2);
  std::cout<<S.pop()<<'\n';
  std::cout<<S.pop()<<'\n';
  std::cout<<S.pop()<<'\n';
}

int main(){
  test();
  return 0;
}
```
