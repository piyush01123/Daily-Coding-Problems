
#include <iostream>
#include <cstring>
#include <set>

char firstRecurChar(std::string str){
  std::set<char> chars;
  for (char c: str){
    if (chars.find(c)!=chars.end()){
      return c;
    }
    chars.insert(c);
  }
  return '\0'; //null char 
}

void test(){
  std::cout<<firstRecurChar("acbbac")<<'\n';
  std::cout<<firstRecurChar("abcdef")<<'\n';
}

int main(){
  test();
  return 0;
}
