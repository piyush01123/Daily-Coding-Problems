def ownWays(S, N):
    A = []
    for i in range(2*N-2):
        if S[i]=='S':
            A.append(i)
    B = ['S']*(2*N-2)
    for a in A:
        B[a] = 'E'
    return ''.join(B)

T = int(input())
for t in range(T):
    N = int(input())
    S = input()
    print("Case #%s: %s" %(t+1, ownWays(S, N)))
