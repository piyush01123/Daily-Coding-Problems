
#include <iostream>
#include <time.h>

using namespace std;

struct test{
  int data;
};

test *create(int val){
  test *t = new test;
  t->data = val;
  return t;
}

test createv2(int val){
  test t;
  t.data = val;
  return t;
}

int generate(){
  int t = time(NULL);
  srand(t);
  return rand();
}

int main(){
  cout << generate() << endl;
  // test *t = create(7);
  // cout << (*t).data;
  // test tt;
  // tt.data = 9;
  // cout << tt.data;
  // test ttt = createv2(8);
  // cout << ttt.data;
}
