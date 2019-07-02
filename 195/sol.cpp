
#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> left, std::vector<int> right){
  int n1 = left.size();
  int n2 = right.size();
  int n = n1+n2;
  int i, j, k; i=0; j=0; k=0;
  std::vector<int> sorted(n);
  while (i<n1 && j<n2){
    if (left[i]<right[j]){
      sorted[k] = left[i];
      i++;
    } else {
      sorted[k] = right[j];
      j++;
    }
    k++;
  }
  while (i<n1){
    sorted[k] = left[i];
    i++; k++;
  }
  while (j<n2){
    sorted[k] = right[j];
    j++; k++;
  }
  return sorted;
}

int countHighLow(std::vector<std::vector<int>> M, int i1, int i2, int i3, int i4){
  int nRows = M.size(), nCols = M[0].size(); int n = nRows*nCols, ctr = 0;
  std::vector<int> flatM;
  for (int i=0; i<nCols; i++) flatM.push_back(M[0][i]);
  for (int i=1; i<nRows; i++){
    flatM = merge(flatM, M[i]);
  }
  for (int i=0; i<n; i++){
    if (flatM[i]>=M[i1][i2] && flatM[i]<=M[i3][i4]) ctr++;
  }
  for (int i=0; i<n; i++) std::cout<<flatM[i]<<' '; std::cout<<'\n';
  return n-ctr;
}

void test(){
  std::vector<std::vector<int>> M = {{1, 3, 7, 10, 15, 20},
   {2, 6, 9, 14, 22, 25},
   {3, 8, 10, 15, 25, 30},
   {10, 11, 12, 23, 30, 35},
   {20, 25, 30, 35, 40, 45}};
   std::cout<< countHighLow(M, 1, 1, 3, 3)<<'\n';
}

int main(){
  test();
  return 0;
}
