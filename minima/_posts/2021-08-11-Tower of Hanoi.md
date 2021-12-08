---
layout: post
title: "Tower of Hanoi"
categories: misc
---

The Tower of Hanoi is a puzzle game with three rods and n disks, each a different size.

All the disks start off on the first rod in a stack. They are ordered by size, with the largest disk on the bottom and the smallest one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:

- You can only move one disk at a time.
- A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.
- You cannot place a larger disk on top of a smaller disk.

Write a function that prints out all the steps necessary to complete the Tower of Hanoi. You should assume that the rods are numbered, with the first rod being 1, the second (auxiliary) rod being 2, and the last (goal) rod being 3.

For example, with n = 3, we can do this in 7 moves:
```
Move 1 to 3
Move 1 to 2
Move 3 to 2
Move 1 to 3
Move 2 to 1
Move 2 to 3
Move 1 to 3
```


My Solution(C++):
```

#include <iostream>

void towerOfHanoi(int n, int i, int j, int k){
  //move tower of height n from rod i to rod j with rod k as auxiliary rod
  if (n==1){
    std::cout << "Move " << i << " to " << j << std::endl;
    return;
  }
  towerOfHanoi(n-1, i, k, j);
  std::cout << "Move " << i << " to " << j << std::endl;
  towerOfHanoi(n-1, k, j, i);
}

void test(){
  //create and run test cases
  towerOfHanoi(3, 1, 3, 2);
}

int main(){
  test();
  return 0;
}
```
