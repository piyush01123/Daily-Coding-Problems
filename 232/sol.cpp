
#include <iostream>
#include <string>
#include <unordered_map>

class PrefixMapSum{
private:
  std::unordered_map<std::string, int> H;
public:
  PrefixMapSum(){};
  void insert(std::string key, int val);
  int sum(std::string prefix);
}

void PrefixMapSum::insert(std::string key, int val){
  this->H[key] = val;
}

int PrefixMapSum::sum(std::string prefix){
  int sumVal = 0;
  for (std::string key: this->H.keys()){
    if (key.length>=prefix.length && key.substr(0, prefix.length)==prefix){
      sumVal += this->H[key];
    }
  }
  return sumVal;
}

void test(){
  PrefixMapSum mapsum = PrefixMapSum();
  mapsum.insert("columnar", 3)
  std::cout<< mapsum.sum("col")<<'\n';

  mapsum.insert("column", 2)
  std::cout<< mapsum.sum("col")<<'\n';

}

int main(){
  test();
  return 0;
}
