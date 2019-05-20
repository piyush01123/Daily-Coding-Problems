#include <cstdio>
#include <cstdlib>
int *ret_arr(int N=100){
  int *ptr = (int *)malloc(N*sizeof(int));
  for (int i=0; i<N; i++){
    *(ptr+i) = i*i;
  }
  return ptr;
}
void print_arr(const int *ptr, int N=100){
  for (int i=0; i<N; i++){
    printf("%d\t", *ptr);
    ptr++;
  }
}
int main(){
  int *ptr_N = ret_arr();
  print_arr(ptr_N);
  return 0;
}
