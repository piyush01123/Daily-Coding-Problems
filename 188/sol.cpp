
/*
You can't have a function inside a function in cpp like python. But you do have
function pointers. So in essence, we can create a vector of pairs of function pointers
and their corresponding args as long as the dataytpes remain consistent.
After the creation of such a vector, running the individual functions is trivial.
*/

#include <iostream>
#include <vector>

void print_i(int i){
  std::cout<<i<<'\n';
}


int main(){
  std::vector<std::pair<void(*)(int), int>> func_args;
  std::vector<int> A {1, 2, 3};
  for (int i=0; i<A.size(); i++){
    func_args.push_back(std::make_pair(print_i, A[i]));
  }
  for (auto p: func_args){
    p.first(p.second);
  }
  return 0;
}
