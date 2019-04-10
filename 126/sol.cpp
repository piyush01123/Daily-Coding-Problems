
#include <iostream>

int gcd(int a, int b){
  // std::cout << "A = " << a << " B = " << b << std::endl;
  if (b==0) return a;
  else return gcd(b, a%b);
}

void rotate(int *arr, int n, int d){
  int i = 0;
  int j, temp, k;
  while (i<gcd(n, d)){
    // std::cout << "I = " << i << std::endl;
    temp = arr[i];
    j = i;
    while (1){
      k = j + d;
      if (k>=n) k-=n;
      // std::cout << "J = " << j << " K = " << k << std::endl;
      if (k==i) break;
      arr[j] = arr[k];
      j += d;
    }
    arr[j] = temp;
    i++;
  }
}

int main(){
  int arr[6] = {1,2,3,4,5,6};
  rotate(arr, 6, 2);
  for (int i=0; i<6; i++){
    std::cout << arr[i] << std::endl;
  }
  return  0;
}
