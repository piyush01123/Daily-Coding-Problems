
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
