
#include <iostream>


int *merge(int *left, int *right, int n){
  int *B = new int[n];
  int i, j, k;
  i=0; j=0; k=0;
  while (i<n/2 && j<n-n/2){
    if (left[i]<=right[j]){
      B[k] = left[i];
      k++; i++;
    } else {
      B[k] = right[j];
      k++; j++;
    }
  }
  while (i<n/2){
    B[k] = left[i];
    k++; i++;
  }
  while (j<n-n/2){
    B[k] = right[j];
    k++; j++;
  }
  return B;
}


int *mergeSort(int *arr, int n){
  int *B = new int[n];
  if (n==1){
    B[0] = arr[0];
    return B;
  }

  int m = n/2;
  int *left = new int[m];
  int *right = new int[n-m];
  for (int i=0; i<m; i++) left[i] = arr[i];
  for (int i=0; i<n-m; i++) right[i] = arr[m+i];

  int *leftS = new int[m];
  int *rightS = new int[n-m];
  leftS = mergeSort(left, m);
  rightS = mergeSort(right, n-m);

  int *merged = new int[n];
  merged = merge(leftS, rightS, n);
  return merged;
}


void test(){
  int A[] = {5, 7, 6, 1, 3, 2, 4};
  int n = sizeof(A)/sizeof(A[0]);
  std::cout <<"Original\n";
  for (int i=0; i<n; i++) std::cout << A[i] << " ";

  int *B;
  B = mergeSort(A, n);
  std::cout <<"\nSorted\n";
  for (int i=0; i<n; i++) std::cout << B[i] << " ";
  std::cout<<std::endl;
}


int main(){
  test();
  return 0;
}
