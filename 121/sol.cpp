
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int lps(string S, int i, int j){
  // Recursively finds the length of longest palindromic subsequence
  if (i==j) return 1;
  if (j==i+1 && S.at(i)==S.at(j)) return 2;
  if (S.at(i)==S.at(j)) return lps(S, i+1, j-1) + 2;
  else return max(lps(S, i, j-1), lps(S, i+1, j));
}


int lps_DP(string S){
  // DP solution to length of longest palindromic subsequence
  // vector<vector<int>> A;
  int n = S.length();
  int A[n][n];
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      A[i][j] = 0;
    }
  }
  for (int i=0; i<n; i++) A[i][i] = 1;
  for (int i=0; i<n-1; i++){
    if (S.at(i)==S.at(i+1)) A[i][i+1] = 2;
    else A[i][i+1] = 1;
  }

  for (int l=3; l<n+1; l++){
    // cout << "L = " << l << endl;
    for (int i=0; i<n-l+1; i++){
      int j = i+l-1;
      // cout << i << " " << j << endl;
      if (S.at(i)==S.at(j)) A[i][j] = A[i+1][j-1] + 2;
      else A[i][j] = max(A[i][j-1], A[i+1][j]);
    }
  }

  return A[0][n-1];
}


void test_LPS(){
  // tests the recursive and DP solutions of LPS problem
  string S = "GEEKSFORGEEKS";
  int l = S.length();
  cout << lps(S, 0, l-1) << endl;
  cout << lps_DP(S) << endl;
}


bool makePalindrome(string S, int k){
  // solves given problem
  return S.length()-lps_DP(S) <= k;
}


void test(){
  //creates and runs tests
  string S = "waterrfetawx";
  cout << boolalpha << makePalindrome(S, 2) << endl;
}


int main(){
  // runs the test
  test();
}

 //  printf("Two Dimensional array elements:\n");
 //  for(int i=0; i<n; i++) {
 //   for(int j=0;j<n;j++) {
 //      printf("%d ", A[i][j]);
 //      if(j==n-1){
 //         printf("\n");
 //      }
 //   }
 // }
