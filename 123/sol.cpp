
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isFloat(string s){
  // solution
  try{
    float f = stof(s);
    return true;
  }
  catch(...){
    return false;
  }
}


void test(){
  // builds test cases and tests the function
  vector<string> S {"10", "-10", "10.1", "-10.1", "1e5", "a", "x 1", "a -2","-"};
  for (auto s: S){
    cout << s << " " << boolalpha << isFloat(s) << endl;
  }
}


int main(){
  // runs tests
  test();
}
