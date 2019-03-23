
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
