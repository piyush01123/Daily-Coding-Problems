
#include <iostream>
#include <vector>
#include <algorithm>

struct Interval{
  int start;
  int end;
};

int makeOvelap(std::vector<Interval> v){
  //minimum no. of intervals to remove to make remaining ones non-overlapping
  auto comp_fn = [](Interval i1, Interval i2){return i1.start<i2.start;};
  std::sort(v.begin(), v.end(), comp_fn);
  int res = 0, pre = 0;
  for (int i=1; i<v.size(); i++){
    if (v[i].start<v[pre].end){
      res++;
      if (v[i].end<v[pre].end) pre = i;
    } else {
      pre = i;
    }
  }
  return res;
}

void test(){
  std::vector<Interval> intervals {{7, 9}, {2, 4}, {5, 8}};
  std::cout<<makeOvelap(intervals)<<'\n';
}

int main(){
  test();
  return 0;
}
