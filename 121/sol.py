
# Length of longest palindromic subsequence in S - recursive soln
def lps(S: str, i: int, j: int)->int:
    if i==j:
        return 1
    if j==i+1 and S[i]==S[j]:
        return 2
    if S[i]==S[j]:
        return lps(S, i+1, j-1) + 2
    return max(lps(S, i, j-1), lps(S, i+1, j))

# Length of longest palindromic subsequence in S - DP soln
def lps_DP(S: str)->int:
    n = len(S)
    A = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        A[i][i] = 1
    for i in range(n-1):
        A[i][i+1] = 2 if S[i]==S[i+1] else 1
    for a in A:
        print(a)
    for l in range(3, n+1):
        print('L = ', l)
        for i in range(n-l+1):
            j = i+l-1
            print(i, j)
            if S[i]==S[j]:
                A[i][j] = A[i+1][j-1] + 2
            else:
                A[i][j] = max(A[i][j-1], A[i+1][j])
    print('_'*25)
    for a in A:
        print(a)
    return A[0][n-1]

def test():
    S = "GEEKSFORGEEKS"
    print(lps(S, 0, len(S)-1))
    print(lps_DP(S))

def makePalindrome(S: str, k: int)->bool:
    return len(S)-lps_DP(S) <= k

if __name__=='__main__':
    # print(makePalindrome('waterrfetawx', 2))
    print(makePalindrome('GEEKSFORGEEKS', 2))
