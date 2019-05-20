#include <stdio.h>
#include <stdlib.h>
int *ret_arr(int N=100){
  int *ptr = malloc(N*sizeof(int));
  for (int i=0; i<N; i++){
    *(ptr+i) = i*i;
  }
  return ptr;
}
void print_arr(int *ptr, int N=100){
  for (int i=0; i<N; i++){
    printf("%d\t", *(ptr+i));
  }
}
int main(){
  int *ptr_N;
  ptr_N = ret_arr();
  print_arr(ptr_N);
  return 0;
}
