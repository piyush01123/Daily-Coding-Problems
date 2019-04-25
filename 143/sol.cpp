
#include <iostream>

int *pivotArray(int *arr, int pivot, int n){
  int *B = new int[n];
  int k = 0;
  for (int i=0; i<n; i++){
    if (arr[i]<pivot){
      B[k] = arr[i];
      k++;
    }
  }
  for (int i=0; i<n; i++){
    if (arr[i]==pivot){
      B[k] = arr[i];
      k++;
    }
  }
  for (int i=0; i<n; i++){
    if (arr[i]>pivot){
      B[k] = arr[i];
      k++;
    }
  }
  return B;
}

void test(){
  int lst[] = {9, 12, 3, 5, 14, 10, 10};
  int n = sizeof(lst)/sizeof(lst[0]);
  std::cout<<"\nOriginal array\n";
  for (int i=0; i<n; i++) std::cout<<lst[i]<<" ";std::cout<<std::endl;

  int *lst_piv;
  lst_piv = pivotArray(lst, 10, n);
  std::cout<<"\nPivoted array\n";
  for (int i=0; i<n; i++) std::cout<<lst_piv[i]<<" ";std::cout<<std::endl;
}

int main(){
  test();
  return 0;
}
