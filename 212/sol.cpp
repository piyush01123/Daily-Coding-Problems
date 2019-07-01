
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

std::string intToExcelCol(int n){
  std::string col;
  int len = log(double(n))/log(double(26));;
  int i=0;
  while (n>0){
    int r = n%26;
    col.push_back('A'+r-1);
    n = n/26;
  }
  std::reverse(col.begin(), col.end());
  return col;
}

void test(){
  std::cout<<intToExcelCol(17)<<'\n';
  std::cout<<intToExcelCol(27)<<'\n';
  std::cout<<intToExcelCol(53)<<'\n';
  std::cout<<intToExcelCol(118)<<'\n';
  std::cout<<intToExcelCol(36912)<<'\n';
}

int main(){
  test();
  return 0;
}
