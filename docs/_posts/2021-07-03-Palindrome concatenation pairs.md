---
layout: post
title: "Palindrome concatenation pairs"
categories: misc
---

Good morning! Here's your coding interview problem for today.

This problem was asked by Airbnb.

Given a list of words, find all pairs of unique indices such that the concatenation of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)].


My Solution(C++):
```

#include <vector>
#include <iostream>
#include <cstring>

bool isPalindrome(std::string str){
  int n =str.length();
  int m = n/2;
  for (int i=0; i<m; i++){
    if (str.at(i)!=str.at(n-i-1)) return false;
  }
  return true;
}

std::vector<std::pair<int, int>> allPalindromes(std::vector<std::string> words){
  std::vector<std::pair<int, int>> pairs;
  for (int i=0; i<words.size(); i++){
    for (int j = 0; j<words.size(); j++){
      if (i==j){
        continue;
      }
      std::string word = words[i]+words[j];
      if (isPalindrome(word)){
        pairs.push_back(std::make_pair(i, j));
      }
    }
  }
  return pairs;
}

void test(){
  std::vector<std::string> words = {"code", "edoc", "da", "d"};
  std::vector<std::pair<int, int>> pairs = allPalindromes(words);
  std::cout<<'[';
  for (auto p: pairs) std::cout<<'('<<p.first<<' '<<p.second<<"), ";
  std::cout<<']'<<'\n';
}

int main(){
  test();
  // std::string x = "aqua";
  // std::string y = "man";
  // std::vector<std::string> v = {"aagaa", "agag", "aglga", "aglollga", "agllga"};
  // std::cout<<x+y<<'\n';
  // for (auto i: v) std::cout<<i<<" palindrome? "<<std::boolalpha<<isPalindrome(i)<<'\n';
  return 0;
}
```
