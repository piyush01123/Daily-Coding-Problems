// exact same as the other one, uses stl vectors instead of arrays/ptrs.
#include <iostream>
#include <vector>
#include <iterator>

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
  int i, j, k;
  i = 0; j = 0; k = 0;
  int n1 = left.size();
  int n2 = right.size();
  int n = n1+n2;
  std::vector<int> merged(n);
  while (i<n1 && j<n2){
    if (left[i]<right[j]){
      merged[k] = left[i];
      i++; k++;
    } else {
      merged[k] = right[j];
      j++; k++;
    }
  }
  while (i<n1){
    merged[k] = left[i];
    i++; k++;
  }
  while (j<n2){
    merged[k] = right[j];
    j++; k++;
  }
  return merged;
}

std::vector<int> mergeSort(std::vector<int> v, int n){
  if (n==1) return v;
  int m = n/2;
  std::vector<int> vL, vR;
  for (int i=0; i<m; i++) vL.push_back(v[i]);
  for (int i=m; i<n; i++) vR.push_back(v[i]);
  std::vector<int> vLSorted = mergeSort(vL, m);
  std::vector<int> vRSorted = mergeSort(vR, n-m);
  std::vector<int> vMerged = merge(vLSorted, vRSorted);
  return vMerged;
}

int main(){
  std::vector<int> v = {2, 3, 1, 5, 7, 6, 9, 8, 4};
  int n = v.size();
  std::vector<int> v2 = mergeSort(v, n);
  for (int x: v2) std::cout << x << ' '; std::cout << '\n';
  return  0;
}
