
#include <iostream>
#define TOL 0.001


bool isNearlyEqual(double a, double b){
  // checks if a and b are equal with tolerance value TOL
  double diff = a-b;
  diff = (diff>=0)?diff:-diff;
  return diff<=TOL;
}


double squareRoot(double n){
  // employs binary search to find square root of a number correct within tolerance
  double lower = 0;
  double higher = n;
  double n_sqrt = (lower+higher)/2;
  while (!isNearlyEqual(n_sqrt*n_sqrt, n)) {
    if (n_sqrt*n_sqrt>n) {
      higher = n_sqrt;
    } else {
      lower = n_sqrt;
    }
    n_sqrt = (lower+higher)/2;
  }
  return n_sqrt;
}


void test(){
  // builds and runs test cases
  std::cout << squareRoot(9) << std::endl;
  std::cout << squareRoot(89.121) << std::endl;
  std::cout << squareRoot(49) << std::endl;
  std::cout << squareRoot(0) << std::endl;
  std::cout << squareRoot(1) << std::endl;
}


int main(){
  // run the test
  test();
  return 0;
}
