
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool hopToOtherEnd(std::vector<int> A){
  int i = 0;
  while (i<A.size()) {
    if (i==A.size()-1){
      return true;
    }
    if (A[i]==0){
      return false;
    }
    i = i + A[i];
  }
  return false;
}

int main(){
  std::vector<int> A;
  A = {2, 0, 1, 0};
  cout << hopToOtherEnd(A) << endl;
  A = {1, 1,  0, 1};
  cout << hopToOtherEnd(A) << endl;
  A = {3, 1, 0, 1};
  cout << hopToOtherEnd(A) << endl;
  A = {4, 1, 0, 1};
  cout << hopToOtherEnd(A) << endl;
  A = {2, 1, 1, 0};
  cout << hopToOtherEnd(A) << endl;
  return 1;
}
