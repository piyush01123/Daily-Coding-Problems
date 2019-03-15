
def hopToOtherEnd(A: list) -> bool:
    i = 0
    while i < len(A):
        if i==len(A)-1:
            return True
        if A[i]==0:
            return False
        i = i + A[i]
    return False


if __name__=='__main__':
    print(hopToOtherEnd([2, 0, 1, 0])) #true
    print(hopToOtherEnd([1, 1, 0, 1])) #false
    print(hopToOtherEnd([3, 1, 0, 1])) #true
    print(hopToOtherEnd([4, 1, 0, 1])) #false
    print(hopToOtherEnd([2, 1, 1, 0])) #true
