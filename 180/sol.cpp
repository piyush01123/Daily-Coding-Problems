/*
S = 1 2 3 4 5 6 7 8
Q = {}

S = 1
Q = 8 7 6 5 4 3 2

S = 1 8 7 6 5 4 3 2
Q = {}

S = 1 8
Q = 2 3 4 5 6 7

S = 1 8 2 3 4 5 6 7
Q = {}

S = 1 8 2
Q = 7 6 5 4 3

S = 1 8 2 7 6 5 4 3
Q = {}

S = 1 8 2 7
Q = 3 4 5 6

S = 1 8 2 7 3 4 5 6
Q = {}

S = 1 8 2 7 3
Q = 6 5 4

S = 1 8 2 7 3 6 5 4
Q = {}

S = 1 8 2 7 3 6
Q = 4 5

S = 1 8 2 7 3 6 4 5
Q = {}

S = 1 8 2 7 3 6 4
Q = 5

S = 1 8 2 7 3 6 4 5
Q = {}
*/

#include <stack>
#include <queue>
#include <iostream>

void interleaveHalves(std::stack<int> &S){
    std::queue<int> Q;
    int n = S.size();
    for (int i=0; i<n; i++){
      while (S.size()>i+1){
        int top = S.top();
        S.pop();
        Q.push(top);
      }
      while (!Q.empty()){
        int bottom = Q.front();
        S.push(bottom);
      // std::cout<<bottom<<',';
        Q.pop();
      }
      // std::cout<<'\n';
    }
}

void test(int n){
  std::stack<int> S;
  for (int i=1; i<=n; i++) S.push(i);
  interleaveHalves(S);
  while (!S.empty()){
    std::cout<<S.top()<<' ';
    S.pop();
  }
  std::cout<<'\n';
}

int main(){
  std::cout<<"Stacks will be printed top to bottom"<<'\n';
  std::cout<<"Interleaved halves for N = 5"<<'\n';
  test(5);
  std::cout<<"Interleaved halves for N = 6"<<'\n';
  test(6);
  std::cout<<"Interleaved halves for N = 8"<<'\n';
  test(8);
  return 0;
}
