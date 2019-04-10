
import random

def noFours(N):
    s = str(N)
    t = s.replace('4','3')
    A = int(t)
    B = N-A
    return A, B


# T = int(input())
# for t in range(T):
#     N = int(input())
#     A, B = noFours(N)
#     print("Case #%s: %s %s" %(t+1, A, B))

for _ in range(10000):
    N = random.randint(1, 10**9)
    N_str = str(N)
    if '4' not in N_str:
        pos = random.randint(1, len(N_str))
        N = int(N_str[:pos]+'4'+N_str[pos+1:])
    print(N, noFours(N))
