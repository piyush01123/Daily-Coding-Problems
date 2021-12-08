---
layout: post
title: "Rotate 2-D array in-place"
categories: misc
---

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:
```
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
```
you should return:

```
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
```
Follow-up: What if you couldn't use any extra space?


My Solution(C++):
```

#include <vector>
#include <iostream>
#include <assert.h>

void rotateClockWise(std::vector<std::vector<int>> &matrix){
  int N = matrix.size();
  assert (N==matrix[0].size());
  for (int i=0; i<N;  i++){
    for (int j=i; j<N; j++){
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
  for (int i=0; i<N; i++){
    for (int j=0; j<N/2; j++){
      int temp = matrix[i][j];
      matrix[i][j] = matrix[i][N-j-1];
      matrix[i][N-j-1] = temp;
    }
  }
}

void printMatrix(const std::vector<std::vector<int>> a){
  for (int i=0; i<a.size(); i++){
    for (int j=0; j<a[0].size(); j++){
      std::cout<<a[i][j]<<" ";
    }
    std::cout<<'\n';
  }
}

void test(){
  std::vector<std::vector<int>> A = \
    { {1, 2, 3},
     {4, 5, 6},
     {7, 8, 9} };
  std::cout<<"original matrix:"<<'\n';
  printMatrix(A);
  std::cout<<"Rotated matrix:"<<'\n';
  rotateClockWise(A);
  printMatrix(A);
  std::vector<std::vector<int>> B = \
    { {1, 2, 3, 4},
     {5, 6, 7, 8},
     {9, 10, 11, 12},
     {13, 14, 15, 16} };
  std::cout<<"original matrix:"<<'\n';
  printMatrix(B);
  std::cout<<"Rotated matrix:"<<'\n';
  rotateClockWise(B);
  printMatrix(B);
}

int main(){
  test();
  return 0;
}
```
