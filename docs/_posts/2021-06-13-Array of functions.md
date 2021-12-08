---
layout: post
title: "Array of functions"
categories: misc
---

This problem was asked by Google.

What will this code print out?
```
def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f()
```
How can we make it print out what we apparently want?


My Solution(C++):
```

/*
You can't have a function inside a function in cpp like python. But you do have
function pointers. So in essence, we can create a vector of pairs of function pointers
and their corresponding args as long as the dataytpes remain consistent.
After the creation of such a vector, running the individual functions is trivial.
*/

#include <iostream>
#include <vector>

void print_i(int i){
  std::cout<<i<<'\n';
}


int main(){
  std::vector<std::pair<void(*)(int), int>> func_args;
  std::vector<int> A {1, 2, 3};
  for (int i=0; i<A.size(); i++){
    func_args.push_back(std::make_pair(print_i, A[i]));
  }
  for (auto p: func_args){
    p.first(p.second);
  }
  return 0;
}
```


My Solution(Python):
```
print("buggy output")
def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f()


print("method 1")
def print_i(i):
    print(i)

def make_functions(func, args):
    for arg in args:
        func(arg)

make_functions(print_i, [1, 2, 3])



print("method 2")
def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i(i):
            print(i)
        flist.append([print_i, i])

    return flist

functions = make_functions()
print(functions)
for f, i in functions:
    f(i)
```
