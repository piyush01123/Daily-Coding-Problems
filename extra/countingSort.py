
"""
Linear time sorting
"""

def countingSort(A: list) -> list:
    min_A, max_A = A[0], A[0]
    for a in A:
        if a>max_A:
            max_A = a
        if a<min_A:
            min_A = a
    H = {k: 0 for k in range(min_A, max_A+1)}
    for a in A:
        H[a]+=1
    for k in range(min_A+1, max_A+1):
        H[k]+=H[k-1]
    B = [None for _ in range(len(A))]
    for a in A:
        B[H[a]-1] = a
        H[a]-=1
    return B

print(countingSort([1, 4, 1, 2, 7, 5, 2]))
