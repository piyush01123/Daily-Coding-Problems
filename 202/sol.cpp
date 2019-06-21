
#include <iostream>
#include <vector>

bool isPalindrome(int num){
  std::vector<int> digits;
  while (num>0){
    digits.push_back(num%10);
    num/=10;
  }
  // for (int d: digits) std::cout<<d<<' ';std::cout<<'\n';
  int n = digits.size();
  for (int i=0; i<n/2; i++){
    if (digits[i]!=digits[n-i-1]){
      return false;
    }
  }
  return true;
}

void test(){
  std::cout<<std::boolalpha<<isPalindrome(121)<<'\n';
  std::cout<<std::boolalpha<<isPalindrome(888)<<'\n';
  std::cout<<std::boolalpha<<isPalindrome(678)<<'\n';
}

int main(){
  test();
}
