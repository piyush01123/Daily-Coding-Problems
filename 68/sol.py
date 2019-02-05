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
