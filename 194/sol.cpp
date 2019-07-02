
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

/*
Consider two sets of points: P on y=0 and Q on y=1.
Sort P and arrange Q such that indices in new Q match those of P before sorting
Then the number of intersections is the inversion count in the new Q.
Inversion count of an array is the number of pairs i<j such that A[i]>A[j]
We can write a modified version of mergesort for getting this number for an array.
Our implementation achieves this by passing a counter by reference inside the merge method
*/

std::vector<int> merge(std::vector<int> left, std::vector<int> right, int &count){
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
      count = count+n1-i;
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

std::vector<int> mergeSort(std::vector<int> v, int &count){
  int n = v.size();
  if (n==1) return v;
  int m = n/2;
  std::vector<int> left, right;
  for (int i=0; i<m; i++) left.push_back(v[i]);
  for (int i=m; i<n; i++) right.push_back(v[i]);
  std::vector<int> leftSorted = mergeSort(left, count);
  std::vector<int> rightSorted = mergeSort(right, count);
  std::vector<int>  vSorted = merge(leftSorted, rightSorted, count);
  return vSorted;
}

void testFuns(){
  std::vector<int> A = {1, 20, 6, 4, 5};
  int count = 0;
  std::vector<int> sortedA = mergeSort(A, count);
  for (int i=0; i<sortedA.size(); i++) std::cout<<sortedA[i]<<' '; std::cout<<'\n';
  std::cout<<"Inversion Count = "<<count<<'\n';
}

int countIntersections(std::vector<int> p, std::vector<int> q){
  int ctr1 = 0;
  std::vector<int> pSorted = mergeSort(p, ctr1);
  // for (int i=0; i<pSorted.size(); i++) std::cout<<pSorted[i]<<' '; std::cout<<'\n';
  std::vector<int> qNew;
  for (int i=0; i<p.size(); i++){
    // std::vector<int>::iterator it = std::find(p.begin(), p.end(), pSorted[i]);
    int idx = std::find(p.begin(), p.end(), pSorted[i])-p.begin();
    qNew.push_back(q[idx]);
  }
  // for (int i=0; i<qNew.size(); i++) std::cout<<qNew[i]<<' '; std::cout<<'\n';
  int ctr2 = 0;
  mergeSort(qNew, ctr2);
  return ctr2;
}

void test(){
  std::vector<int> P = {7,2,4,8,10,6,9};
  std::vector<int> Q = {2,5,4,6,7,8,1};
  int count = countIntersections(P, Q);
  std::cout<<"Number of Intersections = "<<countIntersections(P, Q)<<'\n';
}

int main(){
  // testFuns();
  test();
  return 0;
}
