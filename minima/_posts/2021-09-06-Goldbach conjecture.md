---
layout: post
title: "Goldbach conjecture"
categories: misc
---

This problem was asked by Alibaba.

Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.

A solution will always exist. See [Goldbach’s conjecture](https://en.wikipedia.org/wiki/Goldbach%27s_conjecture).

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then
[a, b] < [c, d]
If a < c OR a==c AND b < d.


My Solution(C++):
```

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
```


My Solution(Python):
```

def godbachPair(num: int) -> 'list(int)':
    if num%2==1 or num<4:
        return None
    if num==4 or num==6:
        return [num//2, num//2]
    primes = {2}
    for i in range(3, num):
        found = False
        for p in primes:
            if p*p>i:
                break
            if i%p==0:
                found = True
                break
        if found == False:
            if num-i in primes:
                return ([num-i, i])
            primes.add(i)


if __name__=='__main__':
    for num in range(4, 101, 2):
        print(num, godbachPair(num))
```
