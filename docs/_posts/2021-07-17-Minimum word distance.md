---
layout: post
title: "Minimum word distance"
categories: misc
---

Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in a string.

For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return 1 because there's only one word "cat" in between the two words.


My Solution(C++):
```

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>

int minDistWords(std::string text, std::string word1, std::string word2){
  //split text into words
  std::stringstream ss(text);
  std::vector<std::string> words;
  std::string tok;
  while (std::getline(ss, tok, ' ')) words.push_back(tok);
  // for (auto w: words) std::cout<<w<<' ';std::cout<<'\n';

  std::string match;
  int index, dmin=words.size();
  for (int i=0; i<words.size(); i++){
    if (words[i]==word1 || words[i]==word2){
      if ((words[i]==word1 && match==word2) || (words[i]==word2 && match==word1)){
        dmin = std::min(dmin, i-index-1);
      }
      index = i;
      match = words[i];
    }
  }
  return dmin;
}

void test(){
  std::cout<<minDistWords("dog cat hello cat dog dog hello cat world", "hello", "world")<<'\n';
  std::cout<<minDistWords("hello cat world dog cat hello dog cat dog world", "hello", "world")<<'\n';
  std::cout<<minDistWords("hello world", "hello", "world")<<'\n';
}

int main(){
  test();
  return 0;
}
```
