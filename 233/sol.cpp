
#include <iostream>

int fib(int n){
  if (n==0) return 0;
  if (n==1) return 1;
  return fib(n-2) + fib(n-1);
}

void test(){
  for (int i=0; i<15; i++){
    std::cout<<fib(i)<<'\n';
  }
}

int main(){
  test();
  return 0;
}
