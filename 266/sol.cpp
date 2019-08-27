
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

std::string sortString(std::string str){
  return str; //todo
}

std::unordered_map<std::string, std::vector<std::string>> sortWords(std::vector<std::string> words){
  std::unordered_map<std::string, std::vector<std::string>> mapSorted;
  for (std::string word: words){
    if (mapSorted.find(word) == mapSorted.end){
      mapSorted[word] = std::vector<std::string> {word};
    }
    else {
      std::string sortedWord = sortString(word);
      mapSorted[sortedWord].push_back(word);
    }
  }
  return mapSorted;
}

std::vector<std::string> stepWords(std::string word, std::string dict_file="words.txt"){
  std::unordered_map<std::string, std::vector<std::string>> mapSorted = sortWords(words);
}

void test(){
  std::vector<std::string> wordlist = stepWords("apple");
  for (auto w: wordlist) std::cout<<w<<'\n';
}

int main(){
  test();
  return 0;
}
