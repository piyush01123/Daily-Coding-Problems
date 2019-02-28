
def numOccurMultTable(N: int, X: int) -> int:
    count = 0
    for i in range(1, N+1):
        if N%i==0 and N//i<=(i+1):
            count+=1
    return count

print(numOccurMultTable(6, 12))
