
#include <stdio.h>

__global__ void mykernel(){}

int main(){
  mykernel<<<1, 1>>>();
  printf("Hello World\n");
  return 0;
}
