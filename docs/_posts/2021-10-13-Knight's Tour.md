---
layout: post
title: "Knight's Tour"
categories: misc
---

This problem was asked by Google.

A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.

Given N, write a function to return the number of knight's tours on an N by N chessboard.


My Solution(Python):
```


def allowed_moves(start, visited, N):
    x, y = start//N, start%N
    moves = [(x+2, y+1), (x+2, y-1), \
             (x+1, y+2), (x+1, y-2), \
             (x-1, y+2), (x-1, y-2), \
             (x-2, y+1), (x-2, y-1)]
    return [x*N + y for (x, y) in moves if x>=0 and y>=0 and x<N and y<N and \
            x*N + y not in visited]


def countTours(start, visited, N):
    if len(visited)==N**2:
        return 1
    next_moves = allowed_moves(start, visited, N)
    count = 0
    for move in next_moves:
        visited_tmp = visited.copy()
        visited_tmp.add(move)
        count += countTours(move, visited_tmp, N)
    return count


def countKnightsTours(N):
    num_cells = N**2
    all_tours = 0
    for start in range(num_cells):
        visited = {start}
        num_tours = countTours(start, visited, N)
        print({start: num_tours})
        all_tours += num_tours
    return all_tours


if __name__=='__main__':
    for i in range(1, 6):
        print('For N = {} Number of Knights Tours = {}'.format(i, countKnightsTours(i)))
```
