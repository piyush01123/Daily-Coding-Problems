

def getCounts(S):
    i = 0
    A = []
    while i<len(S):
        j = i+1
        while j<len(S) and S[j]==S[i]:
            j+=1
        A.append(j-i)
        i = j
    return A


def solve(N, B, F):
    while B>1:
        S = (('1'* B + '0'*B)*(N//B))[:N]
        initial = getCounts(S)
        print(S)
        reply = input()
        final = getCounts(reply)
        missing = [i-f for i, f in zip(initial, final)]
        print(missing)
        B//=2
    S = (('1'* B + '0'*B)*(N//B))[:N]
    print(S)
    reply = input()
    






T = int(input())
for _ in range(T):
    N, B, F = map(int, input().split())
    solve(N, B, F)
