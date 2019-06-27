
/*
Apply a permutation on an array
*/

#include <iostream>

template<typename T>
T *apply_permutation(T arr[], int perm[], int size){
  T *arr2 = new T[size];
  for (int i=0; i<size; i++){
    arr2[i] = arr[perm[i]];
  }
  return arr2;
}

void test(){
  char A[] = {'a', 'b', 'c'};
  int P[] = {2, 1, 0};
  char *B = apply_permutation<char>(A, P, 3);
  for (int i=0; i<3; i++) std::cout<<B[i]<<',';std::cout<<'\n';
}


int main(){
  test();
  return 0;
}
