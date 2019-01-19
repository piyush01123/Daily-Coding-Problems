# Recursive solution (Inefficient)
def kSumSubsetPresent(S: list, k: int) -> bool:
    if k==0:
        return True
    if len(S)==0 and k != 0:
        return False
    if S[-1]>k:
        return kSumSubsetPresent(S[:-1], k)
    return kSumSubsetPresent(S[:-1], k) or kSumSubsetPresent(S[:-1], k-S[-1])

def findkSumSubset(S: list, k: int, A = []) -> list:
    if k==0 and len(S)==0:
        return A
    if k!=0 and len(S)==0:
        return "No subset adds to desired target"
    if kSumSubsetPresent(S[:-1], k-S[-1]):
        A.append(S[-1])
        k=k-S[-1]
        S.pop()
        return findkSumSubset(S, k, A)
    else:
        return findkSumSubset(S[:-1], k, A)

S = [12, 1, 61, 5, 9, 2]
k = 24
print(findkSumSubset(S, k, A=[]))

S = [12, 1, 61, 5, 9, 20]
k = 24
print(findkSumSubset(S, k, A=[]))


# DP Solution (Efficient)
def findkSumSubset(S: list, k: int) -> list:
    """
    DP Solution - First create a 2-D matrix A of N rows and k+1 columns
    A[i][j] = True if sum of j is possible with the first i+1 elements
    and False otherwise.
    Then backtrack.
    """
    S = sorted(S)
    N=len(S)
    A = [[None for _ in range(k+1)] for _ in range(len(S))]
    for i in range(len(S)):
        A[i][0] = True
    for j in range(k+1):
        A[0][j] = S[0]==j
    for i in range(len(S)):
        A[i][0] = True
    for i in range(1, N):
        for j in range(1, k+1):
            if j<S[i]:
                A[i][j] = A[i-1][j]
            else:
                A[i][j] = A[i-1][j] or A[i-1][j-S[i]]
    # for line in A:
    #     print(line)
    if not A[-1][-1]:
        return "No subset adds to desired target"
    ans = []
    i=N-1
    j=k
    while j!=0:
        while i>=0 and A[i][j]:
            i-=1
        i+=1
        ans.append(S[i])
        j-=S[i]
    return ans

S = [12, 1, 61, 5, 9, 2]
k = 24
print(findkSumSubset(S, k))

S = [12, 1, 61, 5, 9, 20]
k = 24
print(findkSumSubset(S, k))
