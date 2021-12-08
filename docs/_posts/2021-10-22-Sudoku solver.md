---
layout: post
title: "Sudoku solver"
categories: misc
---

This problem was asked by Dropbox.

Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. The objective is to fill the grid with the constraint that every row, column, and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.

Implement an efficient sudoku solver.


My Solution(Python):
```
"""
Sudoku Solver using backtracking
"""

def find_empty_location(arr,l):
    for row in range(9):
        for col in range(9):
            if arr[row][col]==0:
                l[0]=row
                l[1]=col
                return True
    return False


def get_entities(sudoku, r, c):
    curr_row = sudoku[r]
    curr_col = [row[c] for row in sudoku]
    curr_subgrid = [row[3*(c//3): 3*(c//3+1)] for row in sudoku[3*(r//3): 3*(r//3+1)]]
    curr_subgrid = [j for i in curr_subgrid for j in i]
    return curr_row, curr_col, curr_subgrid


def is_safe(sudoku, r, c, num):
    entities = get_entities(sudoku, r, c)
    return all(num not in entity for entity in entities)


def solveSudoku(sudoku: 'list(list)') -> 'list(list)':
    l = [0, 0]
    if not find_empty_location(sudoku, l):
        return True
    r, c = l
    for num in range(1, 10):
        if is_safe(sudoku, r, c, num):
            sudoku[r][c] = num
            if solveSudoku(sudoku):
                return True
            sudoku[r][c] = 0
        else:
            pass
    return False


if __name__=='__main__':
    sudoku = [[3,0,6,5,0,8,4,0,0],
              [5,2,0,0,0,0,0,0,0],
              [0,8,7,0,0,0,0,3,1],
              [0,0,3,0,1,0,0,8,0],
              [9,0,0,8,6,3,0,0,5],
              [0,5,0,0,9,0,6,0,0],
              [1,3,0,0,0,0,2,5,0],
              [0,0,0,0,0,0,0,7,4],
              [0,0,5,2,0,6,3,0,0]]
    solveSudoku(sudoku)
    for line in sudoku:
        print(line)
```
