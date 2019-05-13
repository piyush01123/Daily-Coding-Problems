
#include <string>
#include <iostream>

std::string reverseBitString(std::string bits){
  std::string rev;
  for (char b: bits){
    if (b=='0') rev.push_back('1');
    else rev.push_back('0');
  }
  return rev;
}

int main(){
  std::string bits = "11110000111100001111000011110000";
  std::string bitRev = reverseBitString(bits);
  std::cout<<"original="<<bits<<"\nreversed="<<bitRev<<'\n';
  return 0;
}
