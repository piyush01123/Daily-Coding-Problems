---
layout: post
title: "Reverse words in a string"
categories: misc
---

This problem was asked by Google.

Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation, can you perform this operation in-place?


My Solution(C++):
```

#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;


string reverseWords(string s){
  vector<string> words;
  string t;
  int i, j;
  i = 0;
  while (i<s.length()){
    j = i;
    while (j<s.length() && s[j] != ' '){
      j ++;
    }
    words.push_back(s.substr(i, j-i));
    i = ++j;
  }
  t = "";
  for (i=words.size()-1; i>=0; i--){
    t += words[i] + ' ';
  }
  return t;
}


int main(){
  cout << reverseWords("hello world here") << endl;
  return 1;
}
```


My Solution(Python):
```

#using split
def reverseWords(s: str) -> str:
    return ' '.join(s.split(' ')[::-1])


#without using split
def reverseWordsV2(s: str) -> str:
    # we can use block1 or block2 to find words
    # BLOCK1
    # words = []
    # curr = ''
    # for l in s:
    #     if l==' ':
    #         words.append(curr)
    #         curr = ''
    #     else:
    #         curr = curr+l
    # words.append(curr)

    #BLOCK2
    words = []
    i = 0
    while i<len(s):
        j = i
        while j<len(s) and s[j] != ' ':
            j+=1
        words.append(s[i:j])
        i = j+1

    t = ''
    for word in words[::-1]:
        t = t + word + " "
    return t


if __name__=='__main__':
    print(reverseWords("hello world here"))
    print(reverseWordsV2("hello world here"))
```
