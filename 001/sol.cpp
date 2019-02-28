#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool twoSum(const vector<int>& nums, int target){
  unordered_set<int> comps;
  for (int num: nums){
    if (comps.find(num) != comps.end()){
      return true;
    }
    comps.insert(target-num);
  }
  return false;
}

int main(){
  vector<int> nums{2, 7, 5, 11, -7, 6, -131};
  int target = 1;
  cout << twoSum(nums, target);
}
