
def partitionEqualSumSubArray(A):
    arrSum=sum(A)
    if arrSum%2==1:
        return False
    halfSum=arrSum//2
    if findkSumSubset(A, halfSum):
        return True
    else:
        return False


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
        return None
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

if __name__=='__main__':
    S = [15, 5, 20, 10, 35, 15, 10]
    print(partitionEqualSumSubArray(S))

    S = [15, 5, 20, 10, 35]
    print(partitionEqualSumSubArray(S))
