
#include <iostream>
#include <vector>
#include <time.h>


class HitCounter{
  //hit counter class
public:
  HitCounter(){}; //constructor
  void record(time_t);
  int total();
  int range(int, int);
  std::vector<time_t> hits;
};


void HitCounter::record(time_t t){
  //store hit time in a vector; not efficient for limited memory
  this->hits.push_back(t);
}

int HitCounter::total(){
  return this->hits.size();
}


int HitCounter::range(int lower, int upper){
  //no. of hits in a range
  int i = 0;
  while (this->hits[i]<lower) i++;
  int j = i;
  while (this->hits[j]<upper) j++;
  return j-i+1;
}


void test(){
  //builds and runs test cases
  HitCounter hitctr;
  time_t t = time(NULL);
  for (int i=0; i<10; i++) hitctr.record(t+i);
  std::cout << hitctr.total() << '\n';
  std::cout << hitctr.range(t+2, t+6) << '\n';
}


int main(){
  //run the test
  // std::cout << "TIME = " << time(NULL) << '\n';
  test();
  return 0;
}
