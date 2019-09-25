
#include <iostream>

int maxRun(int A[], int n){
  int i = 0, j, k, max_run_till_now;
  max_run_till_now = 0;
  while (i<n){
    j = i;
    while (j<n && A[j]==A[i]) j++;
    k=j;
    while (j<n && (A[j]==A[i]||A[j]==A[k])) j++;
    max_run_till_now = ((j-i)>max_run_till_now)?(j-i):max_run_till_now;
    i = k;
  }
  return max_run_till_now;
}

int main(){
  int A[] {2, 1, 2, 3, 3, 1, 3, 5};
  int n = sizeof(A)/sizeof(A[0]);
  std::cout << "Max Run = " << maxRun(A, n) << '\n';
  return 0;
}
