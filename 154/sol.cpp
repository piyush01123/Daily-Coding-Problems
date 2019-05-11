
#include <queue>
#include <iostream>

class Stack{
private:
  std::priority_queue<std::pair<int, int>> H;
  int idx;
public:
  Stack();
  void push(int);
  int pop();
};

Stack::Stack(){
  idx = 0;
}

void Stack::push(int item){
  H.push(std::make_pair(idx, item));
  idx++;
}

int Stack::pop(){
  std::pair<int, int> top = H.top();
  H.pop();
  idx--;
  return top.second;
}

void test(){
  Stack S = Stack();
  S.push(5);
  S.push(3);
  S.push(6);
  std::cout<<S.pop()<<'\n';
  S.push(2);
  std::cout<<S.pop()<<'\n';
  std::cout<<S.pop()<<'\n';
  std::cout<<S.pop()<<'\n';
}

int main(){
  test();
  return 0;
}
