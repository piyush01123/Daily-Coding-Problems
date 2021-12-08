---
layout: post
title: "Non-threatening Queens"
categories: misc
---

This problem was asked by Microsoft.

You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where N queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.


My Solution(Python):
```
"""
Solution is heavily inspired from backtracking guide in extra folder
Board is represented as a list of integers. Each element represents the column
number on which the Queen is present on that row.

For example a board of configuration
* * Q *
Q * * *
* * * Q
* Q * *
is represented by [2, 0, 3, 1]
"""

import unittest

def printBoard(board: list):
    N = len(board)
    print('_'*(2*N))
    for e in board:
        row = ['*' for _ in range(N)]
        row[e] = 'Q'
        print(' '.join(row))
    print('_'*(2*N))

def is_valid(board):
    """
    Check if the current queen is attacked by previous queens
    """
    N = len(board)
    curr_queen_row, curr_queen_col = N-1, board[N-1]
    for row, col in enumerate(board[:-1]):
        diff = abs(curr_queen_col-col)
        if diff==0 or diff==curr_queen_row-row:
            return False
    return True

def n_queens(n, board: list = [], print_bool: bool = True):
    if n == len(board):
        if print_bool:
            printBoard(board)
        return 1
    count = 0
    for col in range(n):
        # creates board
        board.append(col)
        if is_valid(board):
            count += n_queens(n, board)
        board.pop()
    return count

class testClass(unittest.TestCase):
    def test_valid(self):
        good_boards = [[2, 0, 3, 1], [1,3,0,2]]
        results = [is_valid(board) for board in good_boards]
        return self.assertEqual(results, [True]*2)

    def test_invalid(self):
        bad_boards = [[0,1,2,3], [3,2,0,1]]
        results = [is_valid(board) for board in bad_boards]
        return self.assertEqual(results, [False]*2)

    def test_nqueens(self):
        nums = list(range(10))
        nums_queens = [n_queens(num) for num in nums]
        self.assertEqual(nums_queens, [1,1,0,0,2,10,4,40,92,352])

if __name__=='__main__':
    unittest.main()
```
