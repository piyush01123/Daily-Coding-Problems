---
layout: post
title: "Make palindrome with minimum deletions"
categories: misc
---


This problem was asked by Google.

Given a string which we can delete at most k, return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.


My Solution(C++):
```

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
```


My Solution(Python):
```

# Length of longest palindromic subsequence in S - recursive soln
def lps(S: str, i: int, j: int)->int:
    if i==j:
        return 1
    if j==i+1 and S[i]==S[j]:
        return 2
    if S[i]==S[j]:
        return lps(S, i+1, j-1) + 2
    return max(lps(S, i, j-1), lps(S, i+1, j))

# Length of longest palindromic subsequence in S - DP soln
def lps_DP(S: str)->int:
    n = len(S)
    A = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        A[i][i] = 1
    for i in range(n-1):
        A[i][i+1] = 2 if S[i]==S[i+1] else 1
    for a in A:
        print(a)
    for l in range(3, n+1):
        print('L = ', l)
        for i in range(n-l+1):
            j = i+l-1
            print(i, j)
            if S[i]==S[j]:
                A[i][j] = A[i+1][j-1] + 2
            else:
                A[i][j] = max(A[i][j-1], A[i+1][j])
    print('_'*25)
    for a in A:
        print(a)
    return A[0][n-1]

def test():
    S = "GEEKSFORGEEKS"
    print(lps(S, 0, len(S)-1))
    print(lps_DP(S))

def makePalindrome(S: str, k: int)->bool:
    return len(S)-lps_DP(S) <= k

if __name__=='__main__':
    # print(makePalindrome('waterrfetawx', 2))
    print(makePalindrome('GEEKSFORGEEKS', 2))
```
