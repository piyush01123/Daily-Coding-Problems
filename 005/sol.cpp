
#include <iostream>

int addition(int x, int y){
  return x+y;
}

int subtraction(int x, int y){
  return x-y;
}

// int cons(int a, int b, int (*func)(int, int)){
//   int res = (*func)(a, b);
//   return res;
// }
//
// int car(){
//
// }

int pair(int a, int b, int (*f)(int, int)){
  int res = (*f)(a, b);
  return res;
}

int (*cons(int, int))(int a, int b){
  return &pair;
}

int main(){
  // int sum = cons(5, 6, addition);
  // std::cout<<sum<<'\n';
}
