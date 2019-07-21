
#include <unordered_map>
#include <iostream>
#include <vector>


std::unordered_map<char, int> romanDict = {
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
};

void romanToDecimal(char *roman, int len, int &val){
  for (int i=0; i<len; i++){
    if (romanDict[roman[i]]<romanDict[roman[i+1]]){
      val -= romanDict[roman[i]]
    } else {
      val += romanDict[roman[i]]
  }
}

void test(){
  std::vector<char *> v = {"IV", "XL", "XIV", "MCDXLVI"};
  for (char *roman: v){
    std::cout<<roman<< ' '<<romanToDecimal(roman)<<'\n';
  }
}

int main(){
  test();
  return 0;
}
