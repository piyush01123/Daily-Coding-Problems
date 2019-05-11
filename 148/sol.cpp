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

/*
we could also do this in a class
*/

class optIntSum{
// stands for optimal intermal sum
private:
  std::vector<int> cumSums;
public:
  optIntSum(std::vector<int>);
  int sum(int , int);
};

optIntSum::optIntSum(std::vector<int> v){
  int sum = 0;
  for (int i=0; i<v.size(); i++){
    sum+=v[i];
    cumSums.push_back(sum);
  }
}

int optIntSum::sum(int i, int j){
  return cumSums[j-1] - cumSums[i-1];
}

void test2(){
  std::cout << "Running test2" << '\n';
  std::vector<int> L = {1, 2, 3, 4, 5};
  optIntSum ois = optIntSum(L);
  std::cout << ois.sum(1, 3) << '\n';
  std::cout << ois.sum(0, 5) << '\n';
  std::cout << ois.sum(1, 5) << '\n';
  std::cout << ois.sum(0, 3) << '\n';
  std::cout << ois.sum(3, 3) << '\n';
}

int main(){
  test();
  test2();
  return 0;
}
