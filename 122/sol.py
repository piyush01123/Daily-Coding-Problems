
def maxCoins(A):
    n_rows = len(A)
    n_cols = len(A[0])
    coins = [[0 for _ in range(n_cols)] for _ in range(n_rows)]
    coins[0][0] = A[0][0]
    for i in range(1, n_rows):
        coins[i][0] = coins[i-1][0] + A[i][0]
    for j in range(1, n_cols):
        coins[0][j] = coins[0][j-1] + A[0][j]
    for i in range(1, n_rows):
        for j in range(1, n_cols):
            coins[i][j] = max(coins[i][j-1], coins[i-1][j]) + A[i][j]
    return coins[n_rows-1][n_cols-1]


A = [[0, 3, 1, 1], \
     [2, 0, 0, 4], \
     [1, 5, 3, 1]]

print(maxCoins(A))
