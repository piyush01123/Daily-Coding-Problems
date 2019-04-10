
T = int(input())

def damage(sequence):
    i, d, w = 0, 0, 1
    while i < len(sequence):
        if sequence[i]=='S':
            d+=w
        if sequence[i]=='C':
            w*=2
        i+=1
    return d

def reduce_damage(A):
    B = list(A)
    i = len(B)-2
    while i>=0:
        if B[i] =='C' and B[i+1]=='S':
            B[i]='S'
            B[i+1]='C'
            break
        i-=1
    return ''.join(B)

for i in range(1, T+1):
    D, sequence = input().split(' ')
    D_tolerable = int(D)
    D_min = sequence.count('S')
    D_current = damage(sequence)
    if D_current <= D_tolerable:
        print("Case #{}: {}".format(i, 0))
    else:
        if D_min > D_tolerable:
            print("Case #{}: {}".format(i, 'IMPOSSIBLE'))
        else:
            swaps = 0
            while D_current > D_tolerable:
                sequence = reduce_damage(sequence)
                D_current = damage(sequence)
                swaps+=1
            print("Case #{}: {}".format(i, swaps))
