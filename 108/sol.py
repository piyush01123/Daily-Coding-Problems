
def shiftAB(A: str, B: str) -> bool:
    if len(A) != len(B):
        return False
    for i in range(len(A)):
        if A[i:] + A[:i] == B:
            return True
    return False



if __name__=='__main__':
    print(shiftAB('abcde', 'cdeab'))
    print(shiftAB('abc', 'acb'))
    print(shiftAB('aaba', 'abaa'))
