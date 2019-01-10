
def findNonDuplicated(A: list) -> int:
    """O(N) space and O(N) time"""
    H = dict()
    for a in A:
        if a not in H:
            H[a] = 1
        else:
            H[a] += 1
    H = {val:key for key, val in H.items()}
    return H[1]

def findNonDuplicatedSol_2(A: list) -> int:
    """O(N) space and O(1) time"""
    seenOnce, seenTwice = set(), set()
    for a in A:
        if a in seenOnce:
            seenOnce.remove(a)
            seenTwice.add(a)
        elif a in seenTwice:
            seenTwice.remove(a)
        else:
            seenOnce.add(a)
    return seenOnce.pop()


if __name__=='__main__':
    A = [6, 1, 3, 3, 3, 6, 6]
    print(findNonDuplicated(A))
    print(findNonDuplicatedSol_2(A))
    A = [13, 19, 13, 13]
    print(findNonDuplicated(A))
    print(findNonDuplicatedSol_2(A))
