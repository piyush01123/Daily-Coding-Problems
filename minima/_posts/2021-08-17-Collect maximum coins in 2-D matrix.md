---
layout: post
title: "Collect maximum coins in 2-D matrix"
categories: misc
---


This question was asked by Zillow.

You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix
```
0 3 1 1
2 0 0 4
1 5 3 1
```
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.


My Solution(C++):
```

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int maxCoins(vector<vector<int>> A){
  // solution
  int n_rows = A.size();
  int n_cols = A[0].size();
  int coins[n_rows][n_cols];
  for (int i=0; i<n_rows; i++) for (int j=0; j<n_cols; j++) coins[i][j] = 0;
  coins[0][0] = A[0][0];
  for (int i=1; i<n_rows; i++) coins[i][0] = coins[i-1][0] + A[i][0];
  for (int j=1; j<n_cols; j++) coins[0][j] = coins[0][j-1] + A[0][j];
  for (int i=1; i<n_rows; i++) for (int j=1; j<n_cols; j++) coins[i][j] = max(coins[i-1][j], coins[i][j-1]) + A[i][j];
  return coins[n_rows-1][n_cols-1];
}


void test(){
  // creates a test case and runs solution
  vector<vector<int>> A { {0, 3, 1, 1}, {2, 0,  0, 4}, {1, 5, 3, 1} };
  cout << maxCoins(A) << endl;
}


int main(){
  // run test
  test();
}
```


My Solution(Python):
```

def maxCoins(A):
    n_rows = len(A)
    n_cols = len(A[0])
    coins = [[0 for _ in range(n_cols)] for _ in range(n_rows)]
    coins[0][0] = A[0][0]
    for i in range(1, n_rows):
        coins[i][0] = coins[i-1][0] + A[i][0]
    for j in range(1, n_cols):
        coins[0][j] = coins[0][j-1] + A[0][j]
    for i in range(1, n_rows):
        for j in range(1, n_cols):
            coins[i][j] = max(coins[i][j-1], coins[i-1][j]) + A[i][j]
    return coins[n_rows-1][n_cols-1]


A = [[0, 3, 1, 1], \
     [2, 0, 0, 4], \
     [1, 5, 3, 1]]

print(maxCoins(A))
```
