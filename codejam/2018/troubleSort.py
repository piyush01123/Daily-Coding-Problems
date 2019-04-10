
def firstMistake(V: list, N: int):
    V1 = V[::2]
    V2 = V[1::2]
    V1.sort()
    V2.sort()
    W = []
    if N%2==1:
        last_v1 = V1.pop()
    W = [w for p in zip(V1, V2) for w in p]
    if N%2==1:
        W.append(last_v1)
    for i in range(1, N):
        if W[i]<W[i-1]:
            return i-1
    return "OK"


if __name__=='__main__':
    T = int(input())
    for i in range(T):
        N = int(input())
        V = list(map(int, input().split()))
        miss = firstMistake(V, N)
        print("Case #%s: %s" %(i+1, miss))
