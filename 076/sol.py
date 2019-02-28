
def countSorted(A: list) -> int:
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    H = {alphabet[i]: i for i in range(26)}
    N = len(A)
    M = len(A[0])
    count=0
    for i in range(M):
        lst = [H[a[i]] for a  in A]
        if lst==sorted(lst):
            count+=1
    return M-count


A = ['cba', 'daf', 'ghi']
print(countSorted(A))
A = ['abcdef']
print(countSorted(A))
A = ['zyx', 'wvu', 'tsr']
print(countSorted(A))
