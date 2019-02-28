
"""
L(i) = Length of LIS ending at i
L(i) = max(L(j)) + 1 for j in range(i) s.t. A[i]>A[j]
       1, otherwise
"""

# Dynamic Programming Solution
def longestIncreasingSubsequence(A: list) -> int:
    L = []
    for i in range(len(A)):
        l = []
        for j in range(i):
            if A[i]>A[j]:
                l.append(L[j])
        if l:
            L.append(max(l)+1)
        else:
            L.append(1)
    return L[-1]

print(longestIncreasingSubsequence([0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]))
