#include <iostream>

double func(double a){
  std::cout<<"func double "<<a<<'\n';
  return a;
}

int func(int a){
  std::cout<<"func int "<<a<<'\n';
  return a;
}

int main(){
  func(9.731);
  func(3);
}
