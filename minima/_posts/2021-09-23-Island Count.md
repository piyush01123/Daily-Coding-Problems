---
layout: post
title: "Island Count"
categories: misc
---

This problem was asked by Amazon.

Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.
```
1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```


My Solution(Python):
```

def countIslands(grid: "list(str)"):
    def transformGrid(grid, row, col):
        if row<0 or col<0 or row>=n_rows or col>=n_cols or grid[row][col]!='1':
            return
        grid[row][col] = 'X'
        pairs = [(row+1, col), (row-1, col), (row, col+1), (row, col-1)]
        for r, c in pairs:
            transformGrid(grid, r, c)

    n_rows, n_cols = len(grid), len(grid[0])
    grid = [list(g) for g in grid]
    island_count = 0
    for row in range(n_rows):
        for col in range(n_cols):
            if grid[row][col]=='1':
                transformGrid(grid, row, col)
                island_count+=1
    return island_count


if __name__=='__main__':
    print(countIslands(['10000', '00110', '01100', '00000', '11001', '11001']))
```
