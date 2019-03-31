
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int maxCoins(vector<vector<int>> A){
  // solution
  int n_rows = A.size();
  int n_cols = A[0].size();
  int coins[n_rows][n_cols];
  for (int i=0; i<n_rows; i++) for (int j=0; j<n_cols; j++) coins[i][j] = 0;
  coins[0][0] = A[0][0];
  for (int i=1; i<n_rows; i++) coins[i][0] = coins[i-1][0] + A[i][0];
  for (int j=1; j<n_cols; j++) coins[0][j] = coins[0][j-1] + A[0][j];
  for (int i=1; i<n_rows; i++) for (int j=1; j<n_cols; j++) coins[i][j] = max(coins[i-1][j], coins[i][j-1]) + A[i][j];
  return coins[n_rows-1][n_cols-1];
}


void test(){
  // creates a test case and runs solution
  vector<vector<int>> A {{0, 3, 1, 1}, {2, 0,  0, 4}, {1, 5, 3, 1}};
  cout << maxCoins(A) << endl;
}


int main(){
  // run test
  test();
}
