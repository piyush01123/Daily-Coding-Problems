
#include <iostream>
#include <vector>
#include <algorithm>


struct bitArray{
  int size;
  // memory stores indices containing ones.
  std::vector<int> memory;

  bitArray(int size){
    this->size = size;
    this->memory.reserve(size);
  }
  void set(int i, int val){
    if (val!=1 && val!=0) std::cout << "\nInvalid value\n";
    if (val==1) this->memory.push_back(i);
  }

  int get(int i){
    if (std::find(this->memory.begin(), this->memory.end(), i) != this->memory.end()){
      return 1;
    } else {
      return 0;
    }
  }
};


void test(){
  bitArray arr(3);
  arr.set(0, 1);
  arr.set(1, 0);
  arr.set(2, 1);
  std::cout<<arr.get(0)<<std::endl;
  std::cout<<arr.get(1)<<std::endl;
  std::cout<<arr.get(2)<<std::endl;
}

int main(){
  test();
  return 0;
}
