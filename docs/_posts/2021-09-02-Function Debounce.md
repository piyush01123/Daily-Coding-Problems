---
layout: post
title: "Function Debounce"
categories: misc
---

This problem was asked by Facebook.

Given a function f, and N return a debounced f of N milliseconds.

That is, as long as the debounced f continues to be invoked, f itself will not be called for N milliseconds.


My Solution(Python):
```

import time
from threading import Timer
import unittest


def debounce(N):
    def inner(func):
        def debounced(*args, **kwargs):
            def call_fn():
                rv = func(*args, **kwargs)
                return rv
            try:
                debounced.timer.cancel()
            except AttributeError:
                pass
            debounced.timer = Timer(N, call_fn)
            debounced.timer.start()
        return debounced
    return inner


class TestDebounce(unittest.TestCase):
    def setUp(self):
        self.count = 0

    @debounce(10)
    def increment(self):
        self.count += 1

    def test_debounce(self):
        self.assertEqual(self.count, 0)
        self.increment()
        self.assertEqual(self.count, 0)
        time.sleep(10.01)
        self.assertEqual(self.count, 1)


if __name__ == '__main__':
    unittest.main()
```
