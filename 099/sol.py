
def longestConsecutiveSequence(arr: list) -> int:
    if not arr:
        return 0
    arr = set(arr)
    max_len = 0
    for num in arr:
        if num - 1 not in arr:
            curr_len = 1
            curr_num = num
            while curr_num + 1 in arr:
                curr_num += 1
                curr_len += 1
            max_len = max(max_len, curr_len)
        else:
            # We only want to start building the sequence from the smallest member
            continue
    return max_len


if __name__=='__main__':
    print(longestConsecutiveSequence([100, 4, 200, 1, 3, 2]))
    print(longestConsecutiveSequence([100, 3, 99, 4, 98, 2, 99]))
