
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

struct entry{
  int timestamp;
  int count;
  int type; //denote 1 for entry, 0 for exit.
  entry(int ts, int c, int tp){
    timestamp = ts;
    count = c;
    type = tp;
  }
};

std::pair<int, int> busiestPeriod(std::vector<entry> entries){
  std::vector<int> presence;
  int curr = 0;
  for (entry e: entries){
    if (e.type==1) curr+=e.count;
    else curr-=e.count;
    presence.push_back(curr);
  }
  std::vector<int>::iterator it = std::max_element(presence.begin(), presence.end());
  int idx = it-presence.begin();
  return std::make_pair(entries[idx].timestamp, entries[idx+1].timestamp);
}

void test(){
  std::vector<entry> entries = {entry(1526579928, 3, 1), entry(1526580382, 2, 0), entry(1526580393, 1, 0)};
  std::pair<int, int> busyPeriod = busiestPeriod(entries);
  std::cout<<"Busiest Period = {"<<busyPeriod.first<<", "<<busyPeriod.second<<'}'<<'\n';
}

int main(){
  test();
  return 0;
}
