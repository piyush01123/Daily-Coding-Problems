---
layout: post
title: "car, cdr, cons"
categories: misc
---

This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

```
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
```
Implement car and cdr.


My Solution(C++):
```

#include <iostream>

int addition(int x, int y){
  return x+y;
}

int subtraction(int x, int y){
  return x-y;
}

// int cons(int a, int b, int (*func)(int, int)){
//   int res = (*func)(a, b);
//   return res;
// }
//
// int car(){
//
// }

int pair(int a, int b, int (*f)(int, int)){
  int res = (*f)(a, b);
  return res;
}

int (*cons(int, int))(int a, int b){
  int (*f)(int, int);
  return f;
}


struct pair_{
  int a, b;
  int (*f)(int, int);
};


int main(){
  pair_ p1 = {5, 10, addition};
  pair_ p2 = {5, 10, subtraction};
  int a = (p1.f(p1.a, p1.b) + p2.f(p2.a, p2.b))/2;
  int b = (p1.f(p1.a, p1.b) - p2.f(p2.a, p2.b))/2;
  std::cout<<a<<' '<<b<<'\n';
  // int sum = cons(5, 6, addition);
  // std::cout<<sum<<'\n';
}
```


My Solution(Python):
```
def cons(a, b):
  def pair(f):
    return f(a, b)
  return pair

def add(a, b):
  return a+b
def sub(a, b):
  return a-b

def car(pair):
  return (pair(add) + pair(sub))//2

def cdr(pair):
  return (pair(add) - pair(sub))//2

p = cons(3, 8)
print(car(p))
print(cdr(p))
```
