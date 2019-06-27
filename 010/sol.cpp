
#include <iostream>
#include <unistd.h>

int waitRun(int (*f)(int), int arg, int t){
  sleep(t/1000);
  int res = (*f)(arg);
  return res;
}

int dummyF(int n){
  return 2*n;
}

void test(){
  //wait for 2000 milliseconds and then print result dummyF(5)
  std::cout<<waitRun(dummyF, 5, 2000)<<'\n';
}

int main(){
  test();
  return 0;
}
