#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int> & nums){
  int N = nums.size();
  vector<int> leftProducts;
  vector<int> rightProducts;

  leftProducts.push_back(1);
  rightProducts.push_back(1);

  for (int i=1; i<N; i++){
    leftProducts.push_back(nums[i-1]*leftProducts[i-1]);
    rightProducts.push_back(nums[N-i]*rightProducts[i-1]);
  }

  vector<int> prods;
  for (int i=0;i<N; i++){
    prods.push_back(leftProducts[i]*rightProducts[N-i-1]);
  }

 return prods;
}

int main(){
  vector<int> nums{2, 5, 3, 6};
  vector<int> res = productExceptSelf(nums);
  cout << "\nResults\n";
  for (int r: res){
    cout << r << endl;
  }
}
