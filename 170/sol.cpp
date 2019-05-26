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
