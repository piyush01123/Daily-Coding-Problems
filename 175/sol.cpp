
#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#define mp std::make_pair

void markov_chain(std::map<char, std::vector<std::pair<char, double>>> H, int num_steps, char start){
  std::srand(std::time(nullptr));
  std::map<char, int> freq;
  for (int i=0; i<num_steps; i++){
    double p = double(rand()%1000)/double(1000);
    // std::cout<<p<<'\n';
    double cum_prob = 0;
    for (auto entry: H[start]){ // the  pairs
      cum_prob+=entry.second;
      if (p<cum_prob){
        freq[entry.first]++;
        start = entry.first;
        break;
      }
    }
  }
  for (auto x: freq) std::cout<<x.first<<':'<<x.second<<'\n';
}

void test(){
  std::map<char, std::vector<std::pair<char, double>>> H;
  H['a'] = {mp('a', 0.9), mp('b', 0.075), mp('c', 0.025)};
  H['b'] = {mp('a', 0.15), mp('b', 0.8), mp('c', 0.05)};
  H['c'] = {mp('a', 0.25), mp('b', 0.25), mp('c', 0.5)};
  markov_chain(H, 5000, 'a');
}

int main(){
  test();
  return 0;
}
