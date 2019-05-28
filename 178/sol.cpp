
/*
ANALYTICAL SOLUTION
Let's first solve the problem of expected # of tosses for HH and HT.
HH
E = 1/2*(1/2*(2+(E+2))) + 1/2*(E+1)
E = E/4 + 1 + E/2 + 1/2
E/4 = 3/2
E = 6

HT
E = .5*H1 + .5*T1
where H1 = expected # of tosses for HT if toss1 is heads and T1 = exp #toss if toss1 is tails
T1 = 1+E
H1 = .5(2) + .5(H1+1) if we get T on 2nd toss we're done (exp=2) and if we get heads then wee are on the same state as H1.
meaning H1 = 3
So E = 3/2 + (1+E)/2
 E/2 = 2
 E = 4.
We note that HT is higher than HH suggesting consecutively getting the same result requires more tosses in general.


Now, For the actual problem:
<5, 6>
E = 1/6*x + 5/6*y where x is exp # throws given 5 occurs on 1st throw and y is exp # throws given 5 doesn't occur on 1st throw.
y = 1+E
x = 1/6*2 + 1/6*(x+1) + 4/6*(E+2)
x = 1/2 + x/6 + 2E/3 + 4/3
x = 11/6 + x/6 + 2E/3
5x/6 = (2E/3 + 11/6)
x = (4E+11)/5
E = (4E+11)/30 + 5/6*(E+1)
E/30 = 11/30 + 5/6 = 36/30
E = 36

<5, 5>
E = 1/6*x + 5/6*y
y = 1+E
x = 1/6*(2) + 5/6*(E+2) = 2+5E/6
E = 2/6 + 5E/36 + 5/6 + 5E/6
E/36 = 7/6
E = 42
*/

// SIMULATION
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <vector>
// #include <algorithm>
#include <numeric>

double l1 = double(1)/double(6);
double l2 = double(2)/double(6);
double l3 = double(3)/double(6);
double l4 = double(4)/double(6);
double l5 = double(5)/double(6);

void testDice(){
  std::map<int, int> H;
  std::srand(std::time(nullptr));
  for (int i=0; i<10000; i++){
    double p = double(rand())/double(RAND_MAX);
    // std::cout<<p<<'\n';
    if (p<l1) H[1]++;
    else if (p>=l1 && p<l2) H[2]++;
    else if (p>=l2 && p<l3) H[3]++;
    else if (p>=l3 && p<l4) H[4]++;
    else if (p>=l4 && p<l5) H[5]++;
    else if (p>=l5) H[6]++;
  }
  for (auto e: H){
    std::cout<<e.first<<"-->"<<e.second<<'\n';
  }
}

std::vector<int> game1(int n){
  //game 1: estimate the number of dice rolls to get a 5 followed by a 6.
  std::vector<int> v;
  // v1, v2 store number of dice rolls to get desired result in eachof 10k iterations
  v.reserve(n);
  for (int i=0; i<n; i++){
    bool five=false;
    int j=0;
    while (true){
      j++;
      double p = double(rand())/double(RAND_MAX);
      if (five==true && p>=l5){
        v.push_back(j);
        break;
      }
      five = (p>=l4 && p<l5)?true:false;
    }
  }
  // for (int k: v) std::cout<<k<<' '; std::cout<<'\n';
  return v;
}

std::vector<int> game2(int n){
  //game 1: estimate the number of dice rolls to get a 5 followed by a 6.
  std::vector<int> v;
  // v1, v2 store number of dice rolls to get desired result in eachof 10k iterations
  v.reserve(n);
  for (int i=0; i<n; i++){
    bool five=false;
    int j=0;
    while (true){
      j++;
      double p = double(rand())/double(RAND_MAX);
      if (five==true && p>=l4 && p<l5){
        v.push_back(j);
        break;
      }
      five = (p>=l4 && p<l5)?true:false;
    }
  }
  // for (int k: v) std::cout<<k<<' '; std::cout<<'\n';
  return v;
}

void test(){
  int N = 10000;
  std::vector<int> v1 = game1(N);
  std::vector<int> v2 = game2(N);
  double exp_val_game1 = double(std::accumulate(v1.begin(), v1.end(), 0))/double(N);
  double exp_val_game2 = double(std::accumulate(v2.begin(), v2.end(), 0))/double(N);
  std::cout << "expected money to pay for game #1 = " << exp_val_game1 << '\n';
  std::cout << "expected money to pay for game #2 = " << exp_val_game2 << '\n';
  std::cout<< "Hence Alice should play Game #" << (exp_val_game1<exp_val_game2)?1:2;
  std::cout<< std::endl;
}

int main(){
  std::cout<< "Test Dice" << '\n';
  testDice();
  std::cout<< "Test Games" << '\n';
  test();
}
