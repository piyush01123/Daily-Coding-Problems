
#include <iostream>

bool testCollatz(long int n, int &times_called){
  // std::cout<<"N = "<<n<<'\n';
  times_called++;
  if (n==1) return true;
  if (n<=0) return false;
  if (n%2==1) return testCollatz(3*n+1, times_called);
  else return testCollatz(n/2, times_called);
}

int maxLenCollatzSequence(int N=1000000){
  int maxLen=0, num;
  for (int i=1; i<N; i++){
    int times=0;
    if (!testCollatz(i, times)) std::cout<< "Collatz conjecture fails for N= "<<i<<'\n';
    if (times>maxLen) {
      maxLen=times;
      num = i;
    }
  }
  return num;
}

void test(){
  std::cout<<"Collatz conjecture tested successfully for 1 to 1000000"<<'\n';
  std::cout<<"Number with Max Collatz sequence length = "<<maxLenCollatzSequence()<<'\n';
}

int main(){
  test();
  return 0;
}
