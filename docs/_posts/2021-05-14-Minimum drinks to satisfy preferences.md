---
layout: post
title: "Minimum drinks to satisfy preferences"
categories: misc
---

This problem was asked by Amazon.

At a popular bar, each customer has a set of favorite drinks, and will happily accept any drink among this set. For example, in the following situation, customer 0 will be satisfied with drinks 0, 1, 3, or 6.

```
preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}
```
A lazy bartender working at this bar is trying to reduce his effort by limiting the drink recipes he must memorize. Given a dictionary input such as the one above, return the fewest number of drinks he must learn in order to satisfy all customers.

For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.


My Solution(C++):
```

// This problem can be turned into a standard set cover problem.
// https://math.mit.edu/~goemans/18434S06/setcover-tamara.pdf
// https://www.geeksforgeeks.org/set-cover-problem-set-1-greedy-approximate-algorithm/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

// solves the set cover problem by greedy method. This is an approximate solution
int optimumSetCover(std::vector<std::set<int>> setsAvailable, std::vector<int> costs, int num_items){
  int cost_incurred = 0;
  std::set<int> itemsCovered;
  while (itemsCovered.size()<num_items){
    std::vector<double> costRatio(setsAvailable.size()); //cost/(N-I)
    std::cout<<"costs = ";
    for (int i=0; i<setsAvailable.size(); i++){
      // remove items which we already have
      for (int item: itemsCovered) setsAvailable[i].erase(item);
      costRatio[i] = double(costs[i])/double(setsAvailable[i].size());
      std::cout<<costRatio[i]<<' ';
    }
    std::cout<<'\n';
    std::vector<double>::iterator it = std::min_element(costRatio.begin(), costRatio.end());
    int pos = it-costRatio.begin();

    for (int item: setsAvailable[pos]) itemsCovered.insert(item);
    cost_incurred += costs[pos];
    setsAvailable.erase(setsAvailable.begin()+pos);
    costs.erase(costs.begin()+pos);

    std::cout<<"Items Covered = ";
    for (int item: itemsCovered) std::cout<<item<<' ';
    std::cout<<'\n';

  }
  return cost_incurred;
}


void testSetCover(){
  std::vector<std::set<int>> setsAvailable { {4,1,3}, {2,5}, {1,4,3,2} };
  std::vector<int> costs {5,10,3};
  int num_items = 5;
  int optimum_cost = optimumSetCover(setsAvailable, costs, num_items);
  std::cout << "Optimum Cost = " << optimum_cost << '\n';
}

// this function wil turn the problem into set cover problem and then invoke our function
int minDrinkProblem(std::unordered_map<int, std::vector<int>> preferences){
  std::unordered_map<int, std::set<int>> satisfy_drink;
  for (auto item: preferences){
    for (int drink: item.second) satisfy_drink[drink].insert(item.first);
  }
  std::vector<std::set<int>> setsAvailable;
  for (auto item: satisfy_drink) setsAvailable.push_back(item.second);
  std::vector<int> costs(setsAvailable.size(), 1);
  int num_items = preferences.size();
  int optimum_num_drinks = optimumSetCover(setsAvailable, costs, num_items);
  return optimum_num_drinks;
}

void test(){
  std::unordered_map<int, std::vector<int>>
  preferences {
      {0, {0, 1, 3, 6} },
      {1, {1, 4, 7} },
      {2, {2, 4, 7, 5} },
      {3, {3, 2, 5} },
      {4, {5, 8} }
  };
  int optimum_num_drinks = minDrinkProblem(preferences);
  std::cout << "Optimum # of Drinks = " << optimum_num_drinks << '\n';
}

int main(){
  testSetCover();
  test();
  return 0;
}
```
