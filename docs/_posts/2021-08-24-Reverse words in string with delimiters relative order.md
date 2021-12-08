---
layout: post
title: "Reverse words in string with delimiters relative order"
categories: misc
---

This problem was asked by Facebook.

Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. For example, given "hello/world:here", return "here/world:hello"

Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"


My Solution(C++):
```

#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;


string reverseWords(string s, vector<char> delim){
  vector<string> words;
  vector<string> delimiters;
  string word, delimiter, t;
  int i, j;
  i = 0;
  while (i<s.length()){
    j = i;
    while (j < s.length() && find(delim.begin(), delim.end(), s[j]) == delim.end()){
      j ++;
    }
    word = s.substr(i, j-i);
    words.push_back(word);
    delimiter = "";
    while (j < s.length() && find(delim.begin(), delim.end(), s[j]) != delim.end()){
      delimiter += s[j];
      j ++;
    }
    delimiters.push_back(delimiter);
    i = j;
  }
  t = "";
  for (i=0; i<words.size(); i++){
    t += words[words.size()-i-1];
    t += delimiters[i];
  }
  return t;
}


int main(){
  cout << reverseWords("hello/world:here", {':', '/'}) << endl;
  cout << reverseWords("hello/world:here/", {':', '/'}) << endl;
  cout << reverseWords("hello//world:here", {':', '/'}) << endl;
  return 1;
}
```


My Solution(Python):
```

def reverseWords(s: str, delim: list) -> str:
    words = []
    delimiters = []
    i = 0
    while i<len(s):
        j = i
        while j<len(s) and s[j] not in delim:
            j += 1
        words.append(s[i: j])
        delimiter = ""
        while j<len(s) and s[j] in delim:
            delimiter += s[j]
            j+=1
        delimiters.append(delimiter)
        i = j
    # print(words, delimiters)
    return ''.join(a+b for a, b in zip(words[::-1], delimiters))


if __name__=='__main__':
    print(reverseWords(s="hello/world:here", delim=[':', '/']))
    print(reverseWords(s="hello/world:here/", delim=[':', '/']))
    print(reverseWords(s="hello//world:here", delim=[':', '/']))
```
