
#include <iostream>
#include <vector>

struct Stack{
  std::vector<std::vector<int>> list;
  Stack(){}
  void push(int data, int stack_no){
    if (stack_no>=this->list.size()){
      std::vector<int> S;
      S.push_back(data);
      this->list.push_back(S);
    }
    else{
      std::vector<int> S = this->list[stack_no];
      S.push_back(data);
    }
  }
  int pop(int stack_no){
    std::vector<int> S = this->list[stack_no];
    int data = S.back();
    S.pop_back();
    return data;
  }
};

void test(){
  Stack S;
  S.push(10, 0);
  S.push(20, 1);
  S.push(30, 2);
  S.push(40, 0);
  std::cout << S.pop(0) << std::endl;
}

int main(){
  test();
  return 0;
}
