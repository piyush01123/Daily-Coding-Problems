---
layout: post
title: "Minimum Step Move"
categories: misc
---

This problem was asked by Google.

You are in an infinite 2D grid where you can move in any of the 8 directions:

 (x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example:

Input: [(0, 0), (1, 1), (1, 2)]
Output: 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).


My Solution(Python):
```

def minStepMove(positions: 'list(tuple)') -> int:
    steps = 0
    for i in range(len(positions)-1):
        start = positions[i]
        end = positions[i+1]
        x_diff = abs(end[0]-start[0])
        y_diff = abs(end[1]-start[1])
        steps += max(x_diff, y_diff)
    return steps


if __name__=='__main__':
    print(minStepMove([(0, 0), (1, 1), (1, 2)]))
```
