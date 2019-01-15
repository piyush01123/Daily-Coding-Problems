
def kSumSubsetPresent(S: list, k: int) -> bool:
    if k==0:
        return True
    if len(S)==0 and k != 0:
        return False
    if S[-1]>k:
        return kSumSubsetPresent(S[:-1], k)
    return kSumSubsetPresent(S[:-1], k) or kSumSubsetPresent(S[:-1], k-S[-1])

def findkSumSubset(S: list, k: int) -> list:
    """
    DP Solution - First create a 2-D matrix A of len(S) rows and k+1 columns
    A[i][j] = True if j sum is possible with the first i elements
    """
    S = sorted(S)
    A = [[None for _ in range(k+1)] for _ in range(len(S))]
    for i in range(len(S)):
        A[i][0] = True
        for j in range(k+1):
            if 


# S = [12, 1, 61, 5, 9, 2]
# k = 24
# print(kSumSubsetPresent(S, k))

S = [12, 1, 61, 5, 9, 2]
k = 24
print(findkSumSubset(S, k))
