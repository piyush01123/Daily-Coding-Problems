
/*
My solution is this: First sort the weights smallest to largest.
Then take largest weight w. Find cap-w. and find largest item less than  cap-w.
Take that weight.
Then repeat.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int minBoats(std::vector<int> weights, int capacity){
  std::sort(weights.begin(), weights.end());
  int ctr = 0;
  while (weights.size()>0){
    int w_max = weights.back();
    weights.pop_back();
    int i=-1;
    while (weights[i+1]<capacity-w_max) i++;
    if (i>=0) weights.erase(weights.begin()+i);
    ctr++;
  }
  return ctr;
}

int main(){
  std::vector<int> v {100, 200, 150, 80};
  int cap = 200;
  std::cout << "Min # Boats Required = " << minBoats(v, cap) << '\n';
  return 0;
}
