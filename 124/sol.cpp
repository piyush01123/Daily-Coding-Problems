
#include <iostream>
using namespace std;

int numFlips(int n){
  int k = 0;
  while (n>1){
    n/=2;
    k++;
  }
  return k;
}

int main(){
  cout << "n = 25, no. of flips = " << numFlips(25) << endl;
}
