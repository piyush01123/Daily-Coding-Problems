
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> smallerElements(std::vector<int> arr){
  std::vector<int> stack, final;
  for (int i=arr.size()-1; i>=0; i--){
    while(stack.size()>0 && arr[i]<stack.back()){
      stack.pop_back();
      // std::sort(stack.begin(), stack.end());
    }
    final.push_back(stack.size());
    stack.push_back(arr[i]);
    // std::cout<<"I = "<<i<<" stack now = \n";
    // for (int i: stack) std::cout<<i<<' ';std::cout<<'\n';
  }
  std::reverse(final.begin(), final.end());
  return final;
}

void test(){
  std::vector<int> A, B, C, D;
  A = {3, 4, 9, 6, 1};
  B = smallerElements(A);
  for (int b: B) std::cout<<b<<' ';std::cout<<'\n';
  C = {3, 4, 6, 2, 9};
  D = smallerElements(C);
  for (int b: D) std::cout<<b<<' ';std::cout<<'\n';
}

int main(){
  test();
  return 0;
}
