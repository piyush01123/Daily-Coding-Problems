---
layout: post
title: "Integer exponentiation"
categories: misc
---

This problem was asked by Google.

Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long exponentiation(long long, int);

int main(void)
{
  cout << "Enter base\n";
  long long x;
  int y;
  cin >> x;
  cout << "Enter power\n";
  cin >> y;
  long long z = exponentiation(x, y);
  cout << x << " raised to the " << y << "th power is "<< z << endl;
  cout << x << " raised to the " << y << "th power using pow is "<< pow(x, y) << endl;
  return 0;
}

long long exponentiation(long long x, int y)
{
  long long res = 1;
  while (y)
  {
    if (y&1)
    {
      res*=x;
    }
    x*=x;
    y>>=1;
  }
  return res;
}
```


My Solution(Python):
```

import time

def timer(func):
    def f(*args, **kwargs):
        tit=time.time()
        res = func(*args, **kwargs)
        tat=time.time()
        print('Time taken to execute %s is %s seconds' %(func.__name__, tat-tit))
        return res
    return f

@timer
def pow(x, y):
    res=1
    while y:
        if y&1:
            res*=x
        x*=x
        y>>=1
    return res

@timer
def default_pow(x, y):
    # return x**y
    res=1
    while y:
        res*=x
        y-=1
    return res

pairs = [(7, 17), (99, 101), (1273, 71), (79, 7913)]
for base, exp in pairs:
    pow(base, exp)
    default_pow(base, exp)
```
