
def maxSumSubarray(A: list) -> int:
    max_so_far = 0
    max_ending_here = 0
    for a in A:
        max_ending_here = max_ending_here + a
        if max_ending_here < 0:
            max_ending_here = 0
        if max_ending_here > max_so_far:
            max_so_far = max_ending_here
        print('a=%i, meh=%i, msf=%s' %(a, max_ending_here, max_so_far))
    return max_so_far

A = [34, -50, 42, 14, -5, 86]
print(maxSumSubarray(A))
A = [-5, -1, -8, -9]
print(maxSumSubarray(A))
A = [34, -16]
print(maxSumSubarray(A))
A = [-16, 34]
print(maxSumSubarray(A))
