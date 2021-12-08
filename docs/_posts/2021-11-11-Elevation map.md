---
layout: post
title: "Elevation map"
categories: misc
---

This problem was asked by Facebook.

You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [`2, 1, 2]`, we can hold 1 unit of water in the middle.

Given the input `[3, 0, 1, 3, 0, 5]`, we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.


My Solution(C++):
```

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int trapedVolume(std::vector<int> &elevations){
  int lm;
  int rm;
  int trapped = 0;
  for (int i=0; i<elevations.size(); i++){
    lm  = *std::max_element(elevations.begin(), elevations.begin()+i+1);
    rm = *std::max_element(elevations.end()-elevations.size()+i, elevations.end());
    // cout << "LM " << lm << " RM " << rm << " ELEV " << elevations[i] << endl;
    trapped = trapped + std::min(lm, rm) - elevations[i];
  }
  return trapped;
}

int main(){
  std::vector<int> elevations;
  elevations = {2, 1, 2};
  cout << "Trapped Volume = " << trapedVolume(elevations) << endl;
  elevations  = {3, 0, 1, 3, 0, 5};
  cout << "Trapped Volume = " << trapedVolume(elevations) << endl;
  elevations  = {0, 0, 1, 3, 0, 5};
  cout << "Trapped Volume = " << trapedVolume(elevations) << endl;
  return 1;
}
```


My Solution(Python):
```

def trapedVolume(elevations: list) -> int:
    left_max = [max(elevations[:i+1]) for i in range(len(elevations))]
    right_max = [max(elevations[-i-1:]) for i in range(len(elevations))]
    trapped = [min(l, r) - e for l, r, e in zip(left_max, right_max, \
              elevations)]
    return sum(trapped)


if __name__=='__main__':
    print(trapedVolume([2, 1, 2]))
    print(trapedVolume([3, 0, 1, 3, 0, 5]))
    print(trapedVolume([0, 0, 1, 3, 0, 5]))
```
