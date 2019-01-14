
def kSumSubsetPresent(S: list, k: int) -> bool:
    if k==0:
        return True
    if len(S)==0 and k != 0:
        return False
    if S[-1]>k:
        return kSumSubsetPresent(S[:-1], k)
    return kSumSubsetPresent(S[:-1], k) or kSumSubsetPresent(S[:-1], k-S[-1])

def findkSumSubset(S: list, k: int, A: list = []) -> list:
    if k==0:
        return A
    if S[-1]>k:
        return kSumSubset(S[:-1], k)

S = [12, 1, 61, 5, 9, 2]
k = 24
print(findkSumSubset(S, k))
