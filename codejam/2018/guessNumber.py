import sys

def solve(A, B):
    M = (A+B)//2
    print(M)
    sys.stdout.flush()
    res = input()
    if res=='CORRECT':
        return
    if res=='TOO_SMALL':
        A = M+1
    if res=='TOO_BIG':
        B = M-1
    solve(A, B)

if __name__=='__main__':
    T = int(input())
    for _ in range(T):
        A, B = map(int, input().split())
        N = int(input())
        solve(A+1, B)



# import random
# a, b = map(int, input().split())
# secret = random.randint(a, b)
# while True:
#     guess = int(input())
#     if guess==secret:
#         break
#     if guess>secret:
#         print('Too Large')
#     if guess<secret:
#         print('Too small')
