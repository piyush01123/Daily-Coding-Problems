
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>

bool isPermPalin(std::string str){
  std::set<char> chars;
  for (char c: str){
    if (std::find(chars.begin(), chars.end(), c)!=chars.end()){
      //c is in chars set
      chars.erase(c);
    }
    else{
      chars.insert(c);
    }
  }
  return chars.size()<2;
}

void test(){
  std::cout<<std::boolalpha<<isPermPalin("carrace")<<'\n';
  std::cout<<std::boolalpha<<isPermPalin("daily")<<'\n';
  std::cout<<std::boolalpha<<isPermPalin("dailydaly")<<'\n';
}

int main(){
  test();
  return 0;
}
