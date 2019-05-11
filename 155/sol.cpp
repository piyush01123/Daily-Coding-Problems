
#include <iostream>
#include <vector>
#include <unordered_map>

int majorityElement(std::vector<int> lst){
  std::unordered_map<int, int> H;
  for (int elem: lst) H[elem]++;
  for (int elem: lst){
    if (H[elem]>=lst.size()/2){
      return elem;
    }
  }
  return -1;
}

void test(){
  std::cout<<majorityElement({1, 2, 1, 1, 3, 4, 0})<<'\n';
}

int main(){
  test();
  return 0;
}
