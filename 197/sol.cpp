
#include <iostream>
#include <vector>

int gcd(int a, int b){
  if (a%b==0) return b;
  return gcd(b, a%b);
}

void rotate(std::vector<int> &v, int d){
  int n = v.size();
  int gcd_ = gcd(n, d); // std::cout<<gcd_<<'\n';
  for (int i=0; i<gcd_; i++){
    int j = i;
    int temp = v[i];
    while (true){
      int k = j+d;
      if (k>=n) k = k-n;
      if (k==i) break;
      v[j] = v[k];
      j = k;
    }
    v[j] = temp;
  }
}

void test(){
  std::vector<int> A = {1, 2, 3, 4, 5, 6, 7};
  rotate(A, 2);
  for (int a: A) std::cout<<a<<' '; std::cout<<'\n';
}

int main(){
  test();
  return 0;
}
