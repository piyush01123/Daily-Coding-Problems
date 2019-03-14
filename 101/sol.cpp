
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

std::vector<int> goldbachPair(int num){
  std::vector<int> res;
  if (num%2==1 or num<4){
    res = {};
    return res;
  }
  if (num==4 || num==6){
    int n = num/2;
    res = {n, n};
    return res;
  }
  std::vector<int> primes;
  primes.push_back(2);
  for (int i=3; i<num; i++){
    bool is_prime = true;
    for (int p: primes){
      if (p*p > i){
        break;
      }
      if (i%p==0){
        is_prime = false;
        break;
      }
    }
    if (is_prime==true){
      if (std::find (primes.begin(), primes.end(), num-i) != primes.end()){
        res = {num-i, i};
        return res;
      }
      primes.push_back(i);
    }

  }
  return res;
}

int main(){
  std::vector<int> res;
  for (int num=4; num<=100; num+=2){
    cout << "Num = " << num << endl;
    res = goldbachPair(num);
    cout << "Goldbach Pair = " << res[0] << " " << res[1] << endl;
  }
  return 1;
}
