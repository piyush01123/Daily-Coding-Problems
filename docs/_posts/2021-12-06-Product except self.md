---
layout: post
title: "Product except self"
categories: misc
---

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?


My Solution(C++):
```
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int> & nums){
  int N = nums.size();
  vector<int> leftProducts;
  vector<int> rightProducts;

  leftProducts.push_back(1);
  rightProducts.push_back(1);

  for (int i=1; i<N; i++){
    leftProducts.push_back(nums[i-1]*leftProducts[i-1]);
    rightProducts.push_back(nums[N-i]*rightProducts[i-1]);
  }

  vector<int> prods;
  for (int i=0;i<N; i++){
    prods.push_back(leftProducts[i]*rightProducts[N-i-1]);
  }

 return prods;
}

int main(){
  vector<int> nums{2, 5, 3, 6};
  vector<int> res = productExceptSelf(nums);
  cout << "\nResults\n";
  for (int r: res){
    cout << r << endl;
  }
}
```


My Solution(Python):
```
def productExceptSelf(nums):
    leftProducts = [1]
    rightProducts = [1]
    for i in range(1, len(nums)):
        leftProducts.append(nums[i-1]*leftProducts[i-1])
        rightProducts.append(nums[-i]*rightProducts[i-1])
    prods = []
    for i in range(len(nums)):
        prods.append(leftProducts[i]*rightProducts[-1-i])
    return prods
```
