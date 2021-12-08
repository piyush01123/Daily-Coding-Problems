---
layout: post
title: " Job Scheduler"
categories: misc
---

This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.


My Solution(C++):
```

#include <iostream>
#include <unistd.h>

int waitRun(int (*f)(int), int arg, int t){
  sleep(t/1000);
  int res = (*f)(arg);
  return res;
}

int dummyF(int n){
  return 2*n;
}

void test(){
  //wait for 2000 milliseconds and then print result dummyF(5)
  std::cout<<waitRun(dummyF, 5, 2000)<<'\n';
}

int main(){
  test();
  return 0;
}
```


My Solution(Python):
```
import unittest
import time

def jobScheduler(n):
    def inner(func):
        def wrapper(*args, **kwargs):
            import time
            print('start waiting')
            time.sleep(n/1000)
            print('stop waiting')
            rv = func(*args, **kwargs)
            return rv
        return wrapper
    return inner

class testJobScheduler(unittest.TestCase):

    @staticmethod
    @jobScheduler(2000)
    def add(*args):
        print('func called')
        return sum(args)

    def testValue(self):
        ans = self.add(5, 10, 2)
        self.assertEqual(ans, 17)

    def testFunc(self):
        tit = time.time()
        ans = self.add(5, 10, 8)
        tat = time.time()
        self.assertAlmostEqual(tat-tit, 2, places = 0)

if __name__=='__main__':
    unittest.main()
```
