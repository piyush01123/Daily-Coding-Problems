
#include <iostream>
#include <vector>
#include <string>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> v){
  if (v.size()==0){
    out<<"[]\n";
    return out;
  }

  // if (v.size()==1){
  //   out<<'['<<v[0]<<']'<<'\n';
  // }

  out<<'[';
  for (int i=0; i<v.size()-1; i++) out<<v[i]<<", ";
  out<<v[v.size()-1]<<']'<<'\n';
  return out;
}

std::vector<int> startPositions(std::string str, std::string pattern){
  std::vector<int> v;
  for (int i=0; i<(str.length()-pattern.length()+1); i++){
    std::string substring = str.substr(i, pattern.length());
    // std::cout<<substring<<'\n';
    if (substring==pattern) v.push_back(i);
  }
  return v;
}

void test(){
  // std::vector<int> v = {1, 2, 3, 7, 1};
  // std::cout<<v<<'\n';
  std::vector<int> v = startPositions("abracadabra", "abr");
  std::cout<<v;
}

int main(){
  test();
  return 0;
}
