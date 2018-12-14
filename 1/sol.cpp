#include <iostream>
using namespace std;

bool twoSum(int nums[], int target){
  unordered_set<int> comps;
  for (int i=0; i<size(nums); i++){
    if (comps.find(nums[i]) != comps.end()){
      return true;
    }
    comps.insert(target-nums[i]);
  }
}

int main(){
  int nums[] = {2, 7, 5, 11, -7, 6, -131};
  int target = 9;
  cout << twoSum(nums, target);
}
