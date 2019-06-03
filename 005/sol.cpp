
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
  int (*f)(int, int);
  return f;
}


struct pair_{
  int a, b;
  int (*f)(int, int);
};


int main(){
  pair_ p1 = {5, 10, addition};
  pair_ p2 = {5, 10, subtraction};
  int a = (p1.f(p1.a, p1.b) + p2.f(p2.a, p2.b))/2;
  int b = (p1.f(p1.a, p1.b) - p2.f(p2.a, p2.b))/2;
  std::cout<<a<<' '<<b<<'\n';
  // int sum = cons(5, 6, addition);
  // std::cout<<sum<<'\n';
}
