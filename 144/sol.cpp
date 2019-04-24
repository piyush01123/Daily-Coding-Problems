
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define INT_LARGE 100000


int *nearestLargerIndices(int *arr, int n){
  std::vector<std::pair<int, int>> S1, S3;
  std::vector<int> S2, S4;
  for (int i=0; i<n; i++){
    while (!S1.empty() && S1.back().first<=arr[i]) S1.pop_back();
    if (S1.empty()) S2.push_back(INT_LARGE);
    else S2.push_back(S1.back().second);
    S1.push_back(std::make_pair(arr[i], i));
  }
  // std::cout<<"\nS2\n";
  // for (int i=0; i<n; i++) std::cout << S2[i] << " " << std::endl;

  // std::cout<<"\n\nS3 size = "<<S3.size()<<" S4 size = "<<S4.size()<<std::endl;
  for (int i=n-1; i>=0; i--){
    while (!S3.empty() && S3.back().first<=arr[i]) S3.pop_back();
    if (S3.empty()) S4.push_back(INT_LARGE);
    else S4.push_back(S3.back().second);
    S3.push_back(std::make_pair(arr[i], i));
  }
  std::reverse(S4.begin(), S4.end());
  // std::cout<<"\nS4\n";
  // for (int i=0; i<n; i++) std::cout << S4[i] << " " << std::endl;
  int *B = new int[n];
  for (int i=0; i<n; i++){
    B[i] = std::min(S2[i], S4[i]);
    if (B[i]==INT_LARGE) B[i] = -1;
  }
  return B;
}


void test(){
  int A[] = {4, 1, 3, 5, 6};
  int n = sizeof(A)/sizeof(A[0]);
  int *B = nearestLargerIndices(A, n);
  std::cout << "\nOriginal array:\n";
  for (int i=0; i<n; i++){
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;

  for (int i=0; i<n; i++){
    std::cout<<"Index = "<< i << " Index of nearest larger number = " << B[i]<<std::endl;
  }
}


int main(){
  test();
  return 0;
}
