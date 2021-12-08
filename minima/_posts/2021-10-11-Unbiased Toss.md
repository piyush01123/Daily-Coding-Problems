---
layout: post
title: "Unbiased Toss"
categories: misc
---

This problem was asked by Square.

Assume you have access to a function `toss_biased()` which returns 0 or 1 with a probability that's not 50-50 (but also not 0-100 or 100-0). You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.


My Solution(Python):
```

import random
import unittest

def toss_biased(bias_=0.67):
    """
    Args:
        bias: Bias towards 0
    """
    return 1 if random.random()>bias_ else 0

def find_bias(toss_func):
    biases=list()
    for _ in range(100):
        biases.append(sum(toss_func() for _ in range(1000))/1000)
    bias = sum(biases)/100
    return bias

def simulate_unbiased_coin():
    """
    Inspiration: http://www.billthelizard.com/2009/09/getting-fair-toss-from-biased-coin.html
    Method: Toss the biased coin twice. If the results are same, repeat. If they are
    different accept the first toss as result. The reason this works is because P(H, T) and P(T, H) are equal even in a biased coin ie P(H)*P(T).
    So if the two tosses are different, the result of 1st toss against the 2nd toss can be considered to be a fair toss with 50-50 probabilities.
    """
    toss1, toss2 = toss_biased(), toss_biased()
    while toss1==toss2:
        toss1, toss2 = toss_biased(), toss_biased()
    return toss1


class testCoins(unittest.TestCase):
    def test_find_bias(self):
        bias_original = 1-.67
        bias_detected = find_bias(toss_func=toss_biased)
        self.assertAlmostEqual(bias_original, bias_detected, places=2)

    def test_simulate_unbiased_coin(self):
        bias_detected = find_bias(toss_func=simulate_unbiased_coin)
        self.assertAlmostEqual(bias_detected, 0.5, places=2)

if __name__=='__main__':
    unittest.main()
```
