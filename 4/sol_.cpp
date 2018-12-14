#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> mySet;
    for (int num: nums){
        mySet.insert(num);
    }
    int i = 1;
    while (i <= nums.size()){
        if (mySet.find(i) == mySet.end()){
            return i;
        }
        i++;
    }
    return i;
};

int main(){
  vector<int> nums{2, 7, 5, 11, -7, 6, -131};
  cout << firstMissingPositive(nums) << endl;
  vector<int> nums2{1,2,3,6,5,10, 11};
  cout << firstMissingPositive(nums2) << endl;
}
