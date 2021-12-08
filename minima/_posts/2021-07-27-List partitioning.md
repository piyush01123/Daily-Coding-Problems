---
layout: post
title: "List partitioning"
categories: misc
---

This problem was asked by Amazon.

Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].


My Solution(C++):
```

#include <iostream>

int *pivotArray(int *arr, int pivot, int n){
  int *B = new int[n];
  int k = 0;
  for (int i=0; i<n; i++){
    if (arr[i]<pivot){
      B[k] = arr[i];
      k++;
    }
  }
  for (int i=0; i<n; i++){
    if (arr[i]==pivot){
      B[k] = arr[i];
      k++;
    }
  }
  for (int i=0; i<n; i++){
    if (arr[i]>pivot){
      B[k] = arr[i];
      k++;
    }
  }
  return B;
}

void test(){
  int lst[] = {9, 12, 3, 5, 14, 10, 10};
  int n = sizeof(lst)/sizeof(lst[0]);
  std::cout<<"\nOriginal array\n";
  for (int i=0; i<n; i++) std::cout<<lst[i]<<" ";std::cout<<std::endl;

  int *lst_piv;
  lst_piv = pivotArray(lst, 10, n);
  std::cout<<"\nPivoted array\n";
  for (int i=0; i<n; i++) std::cout<<lst_piv[i]<<" ";std::cout<<std::endl;
}

int main(){
  test();
  return 0;
}
```
