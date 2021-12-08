---
layout: post
title: "Deck shuffling with swaps only"
categories: misc
---

This problem was asked by Facebook.

Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.


My Solution(Python):
```

"""
Fisher-Yates Algorithm
https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
"""
import numpy as np

def randK(k: int) -> int:
    return np.random.randint(0, k+1)

def shuffleDeck(cards: list, k: int) -> list:
    n = len(cards)
    for i in range(n-1, 0, -1):
        j = randK(i)
        cards[i], cards[j] = cards[j], cards[i]
    return cards

print(shuffleDeck(cards=list(range(1, 53)), k=10))
```
