import sys

def solve(A):
    x = 2
    cache = set()
    while True:
        while len(cache)<9:
            print(x, 2)
            sys.stdout.flush()
            prepX, prepY = map(int, input().split())
            if prepX==0 and prepY==0:
                return
            cache.add(3*prepX+prepY)
        x+=3
        cache = set()


T = int(input())
for _ in range(T):
    A = int(input())
    solve(A)
