
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<std::string> gray_code(int n){
  // this is not the only way to generate gray code but this is one of the popular methods.
  if (n==1) return {"0", "1"};

  std::vector<std::string> gc_prev = gray_code(n-1);
  std::vector<std::string> gc;

  // 0 + gray_code(n-1)
  for (auto c: gc_prev){
    gc.push_back("0"+c);
  }

  // 1 + reverse_gray_code(n-1)
  std::reverse(gc_prev.begin(), gc_prev.end());
  for (auto c: gc_prev){
    gc.push_back("1"+c);
  }

  return gc;
}


void test(){
  // tests for N = 1 to 5
  for (int n=1; n<=5; n++){
    std::cout << "Gray Code for N = " << n << '\n';
    std::vector<std::string> gc = gray_code(n);
    for (auto c: gc) std::cout << c << " "; std::cout<<'\n';
  }
}


int main(){
  test();
  return 0;
}
