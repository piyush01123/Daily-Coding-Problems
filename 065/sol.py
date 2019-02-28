
def printSpiral(A):
    while A:
        top = A.pop(0)
        bottom = A.pop()
        for item in top:
            print(item)
        for rem in A:
            print(rem.pop())
        for item in bottom[::-1]:
            print(item)
        for rem in A[::-1]:
            print(rem.pop(0))

A = [[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]

printSpiral(A)
