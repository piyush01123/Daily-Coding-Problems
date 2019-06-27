
#include <iostream>
#include <vector>

int findMin(std::vector<int> A, int left, int right){
  int mid = (left+right)/2;
  // std::cout<<"MID = "<<mid<<'\n';
  if (A[mid]<A[mid-1] && A[mid]<A[mid+1]){
    return A[mid];
  }
  if (A[mid]<A[right]){
    return findMin(A, left, mid);
  } else {
    return findMin(A, mid, right);
  }
  return -1;
}

void test(){
  std::vector<int> A = {5, 7, 10, 3, 4};
  std::cout<<findMin(A, 0, A.size()-1)<<'\n';
  std::vector<int> B = {10, 3, 4, 5, 7};
  std::cout<<findMin(B, 0, B.size()-1)<<'\n';
}

int main(){
  test();
  return 0;
}
