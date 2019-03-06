
import itertools


def allPossiblePermutations(alist):
    return list(itertools.permutations(alist))


def allPossiblePermutations_v2(lst):
    if len(lst)==0:
        return []
    if len(lst)==1:
        return [lst]
    all_perms = []
    for i in range(len(lst)):
        item = lst[i]
        rem = lst[:i] + lst[i+1:]
        perms = allPossiblePermutations_v2(rem)
        for perm in perms:
            all_perms.append([item]+perm)
    return all_perms


if __name__=='__main__':
    print(allPossiblePermutations([1, 2, 3]))
    print(allPossiblePermutations_v2([1, 2, 3]))
