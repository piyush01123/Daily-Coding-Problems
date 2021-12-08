---
layout: post
title: "2-Sum problem"
categories: misc
---

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?


My Solution(C++):
```
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
```


My Solution(Python):
```
def twoSum(nums, target):
    comps = set()
    for num in nums:
        if num in comps:
            return True
        comps.add(target-num)
    return False

if __name__=='__main__':
    nums = [2, 7, 5, 11, -7, 6, -131]
    target = 1
    print(twoSum(nums, target))
```


My Solution(Java):
```
import java.util.*;

class TwoSumProblem{
  public static boolean twoSum(int[] nums, int target){
    Set<Integer> comps = new HashSet<>();
    for (int i=0; i<nums.length; i++){
      if (comps.contains(nums[i])){
        return true;
      }
      comps.add(target-nums[i]);
    }
    return false;
  }

  public static void main(String args[]){
    int[] nums = {2, 7, 5, 11, -7, 6, -131};
    int target = 1;
    System.out.println(twoSum(nums, target));
  }
}
```