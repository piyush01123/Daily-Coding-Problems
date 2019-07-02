
#include <iostream>
#include <string>
#include <algorithm>

std::string convertBinary(int n){
  std::string bin = "";
  while (n>0){
    if (n%2==1) bin.push_back('1');
    else bin.push_back('0');
    n/=2;
  }
  std::reverse(bin.begin(), bin.end());
  return bin;
}

int countMaxContinuousOnes(int n){
  std::string binString = convertBinary(n);
  // std::cout<<binString<<'\n';
  int len = binString.length(), i = 0, maxCount = 0;
  while (i<len){
    // std::cout<<"I = "<<i<<'\n';
    int j = i;
    while(binString.at(j)=='1') {
      // std::cout<<"J = "<<j<<'\n';
      j++;
    }
    // std::cout<<"J-I = "<<j-i<<'\n';
    if (maxCount<j-i) maxCount = j-i;
    i = j+1;
  }
  return maxCount;
}

void test(){
  std::cout<<countMaxContinuousOnes(156)<<'\n';
}

int main(){
  test();
  return 0;
}
