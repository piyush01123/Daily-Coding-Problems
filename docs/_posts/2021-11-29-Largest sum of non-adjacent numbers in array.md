---
layout: post
title: "Largest sum of non-adjacent numbers in array"
categories: misc
---

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.


My Solution(C++):
```

#include <iostream>
#include <vector>


int maxRobberyDP(std::vector<int> nums){
 /*
 Problem can be reduced to DP[i] = max(DP[i-2]+ A[i], DP[i-1])
 linear time linear space
 */
 int n = nums.size();
 if (n==1) return nums[0];
 if (n==2) return (nums[0]>nums[1])?nums[0]:nums[1];

 int *dp = new int[n];
 dp[0] = nums[0];
 dp[1] = (nums[0]>nums[1])?nums[0]:nums[1];

 for (int i=2; i<n; i++){
   int a = dp[i-2]+nums[i];
   int b = dp[i-1];
   dp[i] = (a>b)?a:b;
 }
 return dp[n-1];
}


// We can space-optimize this by using two variables for DP[i-1] and DP[i-2]
int maxRobberyDPSpaceOptimized(std::vector<int> nums){
  /*
  Linear time constant space
  */
  int n = nums.size();

  int var1, var2, var3, max_var;
  var1 = nums[0];
  if (n==1) return var1; //var1 stores DP[i-2]

  var2 = (nums[0]>nums[1])?nums[0]:nums[1];
  if (n==2) return var2; //var2 stores DP[i-1]

  for (int i=2; i<n; i++){
    int a = var1 + nums[i];
    int b = var2;
    max_var = (a>b)?a:b;
    var1 = var2;
    var2 = max_var;
  }
  return max_var;
}


void test(){
  std::vector<int> nums;
  nums = {2, 4, 6, 2, 5};
  std::cout<<maxRobberyDP(nums)<<'\n';
  std::cout<<maxRobberyDPSpaceOptimized(nums)<<'\n';
  nums = {5, 1, 1, 5};
  std::cout<<maxRobberyDP(nums)<<'\n';
  std::cout<<maxRobberyDPSpaceOptimized(nums)<<'\n';
}

int main(){
  test();
  return 0;
}
```


My Solution(Python):
```
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        inc = nums[0]
        exc = 0
        for num in nums[1:]:
            old_inc = inc
            inc = exc + num
            exc = max(old_inc, exc)
            # print(exc, inc)
        return max(exc, inc)

if __name__=='__main__':
    print(Solution().rob([5, 1, 1, 5]))
```
