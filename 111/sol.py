
def anagramIndices(W: str, S: str) -> list:
    """
    Given word w and string S, finds all starting indices in S which are anagrams of W.
    """
    H = {}
    for l in W:
         if l in H:
             H[l] += 1
         else:
             H[l] = 1
    idxs = []
    l_s = len(S)
    l_w  = len(W)
    for start in range(l_s-l_w+1):
        F = {}
        for l in S[start: start+l_w]:
            if l in F:
                F[l] += 1
            else:
                F[l] = 1
        if F==H:
            idxs.append(start)
    return idxs


if __name__=='__main__':
    print(anagramIndices(W="ab", S="abxaba"))
