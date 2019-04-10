
#include <iostream>

void towerOfHanoi(int n, int i, int j, int k){
  //move tower of height n from rod i to rod j with rod k as auxiliary rod
  if (n==1){
    std::cout << "Move " << i << " to " << j << std::endl;
    return;
  }
  towerOfHanoi(n-1, i, k, j);
  std::cout << "Move " << i << " to " << j << std::endl;
  towerOfHanoi(n-1, k, j, i);
}

void test(){
  //create and run test cases
  towerOfHanoi(3, 1, 3, 2);
}

int main(){
  test();
  return 0;
}
