
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

std::vector<int> mergeSort(std::vector<int> v){
  int n = v.size();
  if (n==1) return v;
  int m = n/2;
  std::vector<int> left, right;
  for (int i=0; i<m; i++) left.push_back(v[i]);
  for (int i=m; i<n; i++) right.push_back(v[i]);
  std::vector<int> leftSorted = mergeSort(left);
  std::vector<int> rightSorted = mergeSort(right);
  std::vector<int>  vSorted = merge(leftSorted, rightSorted);
  return vSorted;
}

int LargestNonCoPrimeSubset(std::vector<int> A){
  A = mergeSort(A);
  // for (int a: A) std::cout<<a<<' '; std::cout<<'\n';
  int n = A.size();
  std::vector<int> dp(n);
  // dp[i] stores the size of the largest divisible subset where a[i] is the smallest element
  dp[n-1] = 1;
  for (int i=n-2; i>=0; i--){
    int max=0;
    for (int j=i+1; j<n; j++){
      if (A[j]%A[i]==0){
        if (dp[j]>max) max = dp[j];
      }
    }
    dp[i] = 1+max;
  }
  // for (int a: dp) std::cout<<a<<' '; std::cout<<'\n';
  int maxElem=0;
  for (int a: dp) if (a>maxElem) maxElem = a;
  return maxElem;
}

void test(){
  std::vector<int> A = {6, 7, 1, 18, 3, 13, 17};
  std::cout<< LargestNonCoPrimeSubset(A)<<'\n';
}

int main(){
  test();
  return 0;
}
