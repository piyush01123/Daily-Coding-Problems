---
layout: post
title: "Shortest transformation from start word to end word"
categories: misc
---

This problem was asked by Facebook.

Given a start word, an end word, and a dictionary of valid words, find the shortest transformation sequence from start to end such that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If there is no possible transformation, return null. Each word in the dictionary have the same length as start and end and is lowercase.

For example, given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"}, return ["dog", "dot", "dat", "cat"].

Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"}, return null as there is no possible transformation from dog to cat.


My Solution(C++):
```
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
bool isPresent(T t, std::vector<T> v){
  return std::find(v.begin(), v.end(), t) != v.end();
}

std::vector<std::string> possibleWords(std::string start, std::string end){
  int n = start.length();
  std::vector<std::string> vec;
  for (int i=0; i<n; i++){
    if (start[i]!=end[i]){
      std::string w = start;
      w[i] = end[i];
      vec.push_back(w);
    }
  }
  return vec;
}

void transForm(std::string start, std::string end, std::vector<std::string> dictionary, std::vector<std::string> &path){
  if (!isPresent(start, dictionary)){
    return;
  }
  path.push_back(start);
  std::vector<std::string> words = possibleWords(start, end);
  for (auto word: words){
    transForm(word, end, dictionary, path);
  }
}


  return path;
}

void test(){
  std::string start = "dog";
  std::string end = "cat";
  std::vector<std::string> dictionary = {"dot", "dop", "dat", "cat"};
  std::vector<std::string> path = transForm(start, end, dictionary);
  for (std::string word: path) std::cout<<word<<' '; std::cout<<'\n';
}

int main(){
  test();
  // std::vector<std::string> vec {"apple", "banana"};
  // std::string mango = "mango";
  // isPresent(mango, vec);
  return 0;
}

// prod, glan, [pron pran plan glan, grod, glod, glad]
```
