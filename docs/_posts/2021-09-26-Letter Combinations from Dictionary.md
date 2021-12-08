---
layout: post
title: "Letter Combinations from Dictionary"
categories: misc
---

This problem was asked by Yelp.

Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent. You can assume each valid number in the mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].


My Solution(Python):
```

import itertools

def possibleLetters(mapping, digit_string):
    letters = []
    for digit in digit_string:
        letters.append(mapping[digit])
    combs = [''.join(p) for p in itertools.product(*letters)]
    return combs

def main():
    print(possibleLetters({'2': ['a', 'b', 'c'], '3': ['d', 'e', 'f']}, '23'))

if __name__=='__main__':
    main()
```
