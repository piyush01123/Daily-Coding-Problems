
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


vector<int> merge(vector<int> A_minus, vector<int> A_plus){
  // Merge two sorted lists so that merged list remains sorted
  vector<int> A_merge;
  int i = 0, j = 0;
  while (i<A_minus.size() && j<A_plus.size()){
    if (A_minus[i]<=A_plus[j]){
      A_merge.push_back(A_minus[i]);
      i++;
    }else{
      A_merge.push_back(A_plus[j]);
      j++;
    }
  }
  while (i<A_minus.size()){
    A_merge.push_back(A_minus[i]);
    i++;
  }
  while (j<A_plus.size()){
    A_merge.push_back(A_plus[j]);
    j++;
  }
  return A_merge;
}


vector<int> squareSort(vector<int> A){
  // squareSort function that does all the work
  vector<int> A_plus, A_minus, A_merge, A_sqr;
  for (auto a: A){
    if (a>=0) A_plus.push_back(a);
    else A_minus.push_back(-a);
  }
  reverse(A_minus.begin(), A_minus.end());
  A_merge = merge(A_minus, A_plus);
  for (auto a: A_merge){
    A_sqr.push_back(a*a);
  }
  return A_sqr;
}


void test(){
  // Creates and runs a test case
  vector<int> A {-9, -2, 0, 2, 3};
  vector<int> A_sorted = squareSort(A);
  ostream_iterator<int> outit {cout, " "};
  copy(A_sorted.begin(), A_sorted.end(), outit);
  cout << endl;
}


int main(){
  // Run the test
  test();
}
