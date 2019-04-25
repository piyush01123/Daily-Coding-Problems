
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
