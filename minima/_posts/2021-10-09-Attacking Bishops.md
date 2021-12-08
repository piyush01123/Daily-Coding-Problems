---
layout: post
title: "Attacking Bishops"
categories: misc
---

This problem was asked by Google.

On our special chessboard, two bishops attack each other if they share the same diagonal. This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard. Write a function to count the number of pairs of bishops that attack each other. The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

- (0, 0)
- (1, 2)
- (2, 2)
- (4, 0)

The board would look like this:
```
[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
```
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.


My Solution(Python):
```
import itertools

def printBoard(M, positions):
    M = [['*' for _ in range(M)] for _ in range(M)]
    for x, y in positions:
        M[x][y] = 'B'
    for row in M:
        print(row)

def countAttackingBishops(M, positions):
    pairs = itertools.combinations(positions, 2)
    attacking_pairs = 0
    for (x1, y1), (x2, y2) in pairs:
        if x1-y1 == x2-y2 or x1+y1 == x2+y2:
            attacking_pairs+=1
    return attacking_pairs

M = 5
positions = [(0, 0),
(1, 2),
(2, 2),
(4, 0)]

printBoard(M, positions)
print(countAttackingBishops(M, positions))
```
