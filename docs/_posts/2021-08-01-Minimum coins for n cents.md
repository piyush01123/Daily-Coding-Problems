---
layout: post
title: "Minimum coins for n cents"
categories: misc
---

This problem was asked by Google.

Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.


My Solution(C++):
```

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

int minCoinsRequired(std::vector<int> denominations, int amt){
  std::map<int, int> coins;
  std::sort(denominations.begin(), denominations.end());
  std::reverse(denominations.begin(), denominations.end());
  int i=0;
  int num;
  while (amt>0){
    num = amt/denominations[i];
    coins[denominations[i]] = num;
    amt-=denominations[i]*num;
    i++;
  }
  int total = 0;
  for (auto item: coins){
    // std::cout<<item.first<<"$: "<<item.second<<" coins"<<std::endl;
    total+=item.second;
  }
  return total;
}

void test(){
  std::vector<int> american = {1, 5, 10, 25};
  std::cout<<"Min coins required = " << minCoinsRequired(american, 126)<<std::endl;
}

int main(){
  test();
  return 0;
}
```
