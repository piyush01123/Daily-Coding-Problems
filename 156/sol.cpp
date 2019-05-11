
#include <iostream>
#include <algorithm>

//dp soln
int minSqrInts(int n){
  //min sqrd ints which sum to n
  //do not do much here
  if (n<=3){
    return n;
  }

  int A[n+1];
  for (int i=0; i<=3; i++) A[i] = i;
  for (int i=4; i<=n; i++){
    A[i] = i;
    for (int j=1; j*j<=i; j++){
      A[i] = std::min(A[i], 1+minSqrInts(i-j*j));
    }
  }
  return A[n];
}


void test(){
  std::cout<<minSqrInts(13)<<'\n';
  std::cout<<minSqrInts(27)<<'\n';
  std::cout<<minSqrInts(3)<<'\n';
}

int main(){
  test();
  return 0;
}
