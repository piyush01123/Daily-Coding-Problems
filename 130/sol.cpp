
#include <iostream>
#include <algorithm>
#define INT_MIN -1000000


void print2DArray(int arr[3][5]){
  // prints 2D array
  for (int i=0; i<=2; i++){
    for (int j=0; j<5; j++){
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }
  std::cout << "_______________" << '\n';
}


int maxProfit(int *prices, int n, int k){
  // DP solution to max profit on a stock price array with k buy-sells
  //profits[r][c] is a 2-D array that stores max answer for r buy-sells upto c days
  // int profits[k+1][n];
  int profits[k+1][5]; // for calling the print fn. we need to specify 2nd dim
  for (int i=0; i<=k; i++) profits[i][0] = 0;
  for (int j=0; j<n; j++) profits[0][j] = 0;
  for (int i=1; i<=k; i++){
    for (int j=1; j<n; j++){
      int max_so_far = INT_MIN;
      for (int m=0; m<j; m++){
        max_so_far = std::max(max_so_far, prices[j]-prices[m]+profits[i-1][m]);
      }
      profits[i][j] = std::max(max_so_far, profits[i][j-1]);
      print2DArray(profits);
    }
  }
  return profits[k][n-1];
}


int main(){
  int prices[] = {5, 2, 4, 0, 1};
  std::cout << maxProfit(prices, 5, 2) << '\n';
  int arr[5][2] = {{1,2},{3,4},{5,6},{7,8},{9,10}};
  // print2DArray(arr);
  return  0;
}
