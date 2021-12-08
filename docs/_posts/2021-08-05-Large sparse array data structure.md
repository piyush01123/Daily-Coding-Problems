---
layout: post
title: "Large sparse array data structure"
categories: misc
---

This problem was asked by Facebook.

You have a large array with most of the elements as zero.

Use a more space-efficient data structure, SparseArray, that implements the same interface:

- `init(arr, size)`: initialize with the original large array and size.
- `set(i, val)`: updates index at i with val.
- `get(i)`: gets the value at index i.


My Solution(C++):
```

#include <iostream>
#include <map>

class SparseArray{
// sparse array data structure based on map
public:
  SparseArray(int);
  void set(int, int);
  int get(int);
  std::map<int, int> H;
  int size;
};

SparseArray::SparseArray(int size){
  // constructor
  this->size = size;
}

void SparseArray::set(int i, int val){
  // set method
  if (i>=this->size || i<0 ){
    std::cout << "Invalid Index" << std::endl;
    return;
  }
  this->H[i] = val;
  return;
}

int SparseArray::get(int i){
  // get method
  if (i<0 || i>=this->size){
    std::cout << "Invalid Index" << std::endl;
    return -1;
  }
  if (this->H.find(i) == this->H.end()){
    return 0;
  }
  return this->H[i];
}

void test(){
  // builds and runs test cases
  SparseArray sa(100);
  sa.set(1, 4);
  std::cout << sa.get(6) << std::endl;
  std::cout << sa.get(1) << std::endl;
  std::cout << sa.get(101) << std::endl;
}

int main(){
  // run the test
  test();
  return 0;
}
```
