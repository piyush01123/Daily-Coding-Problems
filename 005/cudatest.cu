
// program to return a constant value from device
#include <stdio.h>

__global__ void test(int *n){
  *n = 0;
}

int main(){
  int x, *d_x;
  int size = sizeof(int);
  cudaMalloc((void **)&d_x, size);
  test<<<1,1>>>(d_x);
  cudaMemcpy(&x, d_x, size, cudaMemcpyDeviceToHost);
  printf("returned from device = %d\n", x);
  return 0;
}
