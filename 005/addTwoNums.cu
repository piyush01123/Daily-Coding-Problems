
#include <stdio.h>

__global__ void add(int *a, int *b, int *c){
  *c = *a + *b  ;
}

int main(){
  int a, b, c;
  int *d_a, *d_b, *d_c;
  int size = sizeof(int);

  // int **p1 = &d_a;
  // int **p2 = &d_b;
  // int **p3 = &d_c;
  // cudaMalloc(p1, size);
  // cudaMalloc(p2, size);
  // cudaMalloc(p3, size);
  cudaMalloc((void **)&d_a, size);
  cudaMalloc((void **)&d_b, size);
  cudaMalloc((void **)&d_c, size);
  a = 10; b = 20;

  cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);
  // cudaMemcpy(d_c, &c, size, cudaMemcpyHostToDevice);
  add<<<1,1>>>(d_a, d_b, d_c);
  cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
  printf("SUM=%d\n", c);

  cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
  return 0;
}
