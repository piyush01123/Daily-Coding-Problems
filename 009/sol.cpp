
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
