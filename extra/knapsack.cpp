
/*
KnapSack is a famous NP-Complete problem: Given values of sacks in an array v[]
and their corresponding weighs in another array w[], pick maximum value subject
to total weight not exceeding a quantity W.

We'll write 3 fns: Recursive, DP and DP with O(W) space

This is the 0-1 KnapSack Problem. Because we are taking 0 or 1 of each item.
There are 2 other variant as as well: Bounded (min 0, max M of each item) and
Unbounded: (min  0 of each item).
*/

#include <iostream>

int knapsack_recursive(int v[], int w[], int n, int W){
  // function represents knapsack value with first n items with max weight W
  if (W<=0) return 0;
  if (n==1) return (W>=w[0])?v[0]:0;
  int a = knapsack_recursive(v, w, n-1, W);
  int b = knapsack_recursive(v, w, n-1, W-w[n-1]) + v[n-1];
  return (a>b)?a:b;
}


int knapsack_DP(int v[], int w[], int n, int W){
  int A[n][W+1];
  // A[i][j] represents represents knapsack value with first i items with max wt j
  for (int j=0; j<=W; j++){
    A[0][j] = (j>=w[0])?v[0]:0;
  }
  for (int i=1; i<n; i++){
    for (int j=0; j<=W; j++){
      int a = A[i-1][j];
      int b = A[i-1][j-w[i]] + v[i];
      A[i][j] = (a>b)?a:b;
    }
  }
  return A[n-1][W];
}

int knapsack_DP_space_efficient(int v[], int w[], int n, int W){
  // same as previous except we only maintain 2 rows.
  int A[2][W+1];
  for (int j=0; j<=W; j++){
    A[1][j] = (j>=w[0])?v[0]:0;
  }
  for (int i=1; i<n; i++){
    for (int j=0; j<=W; j++) A[0][j] = A[1][j];
    for (int j=0; j<=W; j++){
      int a = A[0][j];
      int b = A[0][j-w[i]] + v[i];
      A[1][j] = (a>b)?a:b;
    }
  }
  return A[1][W];
}


int main(){
  int v[] {60, 100, 120};
  int w[] {10, 20, 30};
  int n = sizeof(v)/sizeof(v[0]);
  int W = 50;
  int answer1 = knapsack_recursive(v, w, n, W);
  int answer2 = knapsack_DP(v, w, n, W);
  int answer3 = knapsack_DP_space_efficient(v, w, n, W);
  std::cout<<answer1<<'\n';
  std::cout<<answer2<<'\n';
  std::cout<<answer3<<'\n';
  return 0;
}


/*
KnapSack is a NP-Complete Problem. Because its complexity is O(N*W) where W is not
size of input but a value. In a b-base system, W gets stored in some m=log_b(W) bits
Hence O(N*W) can be said to be O(N*b^(m)) which is exponential time complexity.
*/
