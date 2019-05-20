
#include <vector>
#include <iostream>

class array2D{
private:
  std::vector<int> memory;
  int ctr;

public:
  array2D(std::vector<std::vector<int>>);
  int next(void);
  bool has_next(void);
  void  printCTR();
};

array2D::array2D(std::vector<std::vector<int>> v){
  ctr = 0;
  for (auto vec: v){
    for (int i: vec) memory.push_back(i);
  }
}

int array2D::next(void){
  if (ctr < memory.size()){
    return memory[ctr++];
  }
  return -1;
}

bool array2D::has_next(void){
  return ctr < memory.size();
}

void array2D::printCTR(){std::cout<<"ctr value = "<<ctr<<'\n';
std::cout<<"memrotry size = "<<memory.size()<<'\n';}

void test(){
  array2D A = array2D({{1, 2}, {3}, {}, {4, 5, 6}});
  // std::cout<<std::boolalpha<<A.has_next()<<'\n';
  // A.printCTR();
  while (A.has_next()){
    std::cout<<A.next()<<' ';
  }
  std::cout<<'\n';
}

int main(){
  test();
  return 0;
}
