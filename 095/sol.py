
def allPossiblePermutations(lst):
    if len(lst)==0:
        return []
    if len(lst)==1:
        return [lst]
    all_perms = []
    for i in range(len(lst)):
        item = lst[i]
        rem = lst[:i] + lst[i+1:]
        perms = allPossiblePermutations(rem)
        for perm in perms:
            all_perms.append([item]+perm)
    return all_perms


def nextGreaterPermuation(alist):
    lst = sorted(alist)
    perms = allPossiblePermutations(lst)
    idx = perms.index(alist)
    if idx==len(perms)-1:
        return perms[0]
    else:
        return perms[idx+1]


if __name__=='__main__':
    print(nextGreaterPermuation([1, 2, 3]))
    print(nextGreaterPermuation([1, 3, 2]))
    print(nextGreaterPermuation([3, 2, 1]))
