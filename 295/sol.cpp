
#include <iostream>

// The normal pascal triangle using 2D array.
void pascalTriangle(int k){
  std::cout<<"Method 1 \n";
  int A[k][k];
  for (int i=0; i<k; i++){
    A[i][0] = 1;
    A[i][i] = 1;
    for (int j=1;j<i; j++) A[i][j] = A[i-1][j-1]+A[i-1][j];
  }
  for (int i=0;i<k;i++){
    for (int j=0; j<k-i-1; j++) std::cout<<"  ";
    for (int j=0; j<=i; j++) std::cout<<A[i][j]<<"    ";
    std::cout<<'\n';
  }
}

// This is slightly clever. We are modifying the same 1-D array multiple times.
// Everytime starting from the right and upto the position next to first one.
// 1 0 0 0 0
// 1 1 0 0 0
// 1 2 1 0 0
// 1 3 3 1 0
// 1 4 6 4 1
void pascalTriangleSpaceEfficient(int k){
  std::cout<<"Method 2 \n";
  int A[k];
  A[0] = 1;
  for (int i=1; i<k; i++) A[i] = 0;
  for (int i=0; i<k-1; i++){
    for (int j=k-1; j>0; j--) A[j]+=A[j-1];
    for (int i=0; i<k; i++) std::cout<<A[i]<<' ';
    std::cout<<'\n';
  }
}

int main(){
  pascalTriangle(10);
  pascalTriangleSpaceEfficient(10);
  return 0;
}
