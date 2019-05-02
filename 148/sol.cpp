//answer seems to be storing cummulative sums in a hashmap

#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> getCumSums(std::vector<int> v){
  std::unordered_map<int, int> H;
  int sum = 0;
  for (int i=0; i<v.size(); i++){
    sum+=v[i];
    H[i] = sum;
  }
  return H;
}

std::vector<int> L = {1, 2, 3, 4, 5};
std::unordered_map<int, int> H = getCumSums(L);
int sum(int i, int j){
  return H[j-1] - H[i-1];
}

void test(){
  std::cout << sum(1, 3) << '\n';
  std::cout << sum(0, 5) << '\n';
  std::cout << sum(1, 5) << '\n';
  std::cout << sum(0, 3) << '\n';
  std::cout << sum(3, 3) << '\n';
}

int main(){
  test();
  return 0;
}
