
#include <iostream>
#include <set>

int findDuplicate(int arr[], int n){
  int sum = 0;
  for (int i=0; i<n+1; i++) sum+=arr[i];
  return sum-n*(n+1)/2;
}

int findDuplicate_v2(int arr[], int n){
  int xor1 = 0, xor2 = 0;
  for (int i=0; i<n+1; i++) xor1 = xor1^arr[i];
  for (int i=1; i<=n; i++) xor2 = xor2^i;
  return xor2^xor1;
}

int findDuplicate_v3(int arr[], int n){
  std::set<int> S;
  for (int i=0; i<n+1; i++){
    if (S.find(arr[i])!=S.end()) {return arr[i];}
    S.insert(arr[i]);
  }
  return -1;
}

void test(){
  int A[] = {4, 2, 1, 5, 2, 3};
  std::cout<<findDuplicate(A, 5)<<'\n';
  std::cout<<findDuplicate_v2(A, 5)<<'\n';
  std::cout<<findDuplicate_v3(A, 5)<<'\n';
}

int main(){
  test();
  return  0;
}
