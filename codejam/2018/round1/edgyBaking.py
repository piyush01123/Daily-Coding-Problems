import numpy as np

T = int(input())
for t in range(T):
    N, P = map(int, input().split())
    minPeri = 0
    maxPeri = 0
    for _ in range(N):
        W, H = map(int, input().split())
        minP = 2*(W+H+min(W, H))
        maxP = 2*(W+H+np.sqrt(W*W+H*H))
        minPeri+=minP
        maxPeri+=maxP
    print(minPeri, maxPeri, P)
    if P<=minPeri:
        print("Case #%s: %s" %(t+1, minPeri))
    elif P>=maxPeri:
        print("Case #%s: %s" %(t+1, maxPeri))
    else:
        print("Case #%s: %s" %(t+1, P))
