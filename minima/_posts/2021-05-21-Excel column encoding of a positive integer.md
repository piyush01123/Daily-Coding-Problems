---
layout: post
title: "Excel column encoding of a positive integer"
categories: misc
---

This problem was asked by Dropbox.

Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id. For example, given 1, return "A". Given 27, return "AA".


My Solution(C++):
```

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

std::string intToExcelCol(int n){
  std::string col;
  int len = log(double(n))/log(double(26));;
  int i=0;
  while (n>0){
    int r = n%26;
    col.push_back('A'+r-1);
    n = n/26;
  }
  std::reverse(col.begin(), col.end());
  return col;
}

void test(){
  std::cout<<intToExcelCol(17)<<'\n';
  std::cout<<intToExcelCol(27)<<'\n';
  std::cout<<intToExcelCol(53)<<'\n';
  std::cout<<intToExcelCol(118)<<'\n';
  std::cout<<intToExcelCol(36912)<<'\n';
}

int main(){
  test();
  return 0;
}
```
