#include <iostream>
#include <vector>
int main(){
 std::cerr<<"error world"<<'\n';
 std::cout<<"output world"<<'\n';
 std::vector<char> v;
 v.reserve(10);
 std::cout<<v.size()<<'\n';
 return 0;
}
