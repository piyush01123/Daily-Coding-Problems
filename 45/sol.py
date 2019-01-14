import numpy as np

def rand5():
    # np.random.randint returns random integers from the “discrete uniform” distribution of the specified dtype in the “half-open” interval  [low, high)
    return np.random.randint(1, 6)

def rand7():
    """
    Approach: Sample twice and considering a table of 5x5, return the number at the position; if between 1 and 21, else resample.
    1,2,3,4,5,
    6,7,1,2,3,
    4,5,6,7,1,
    2,3,4,5,6,
    7,*,*,*,*
    """
    n1 = rand5()
    n2 = rand5()
    n = 5*(n1-1) + (n2-1) #n is a random number in [0, 24] range
    if n<=20:
        return n%7 + 1
    else:
        return rand7()

A = {}
for _ in range(100000):
    n = rand7()
    if n in A:
        A[n]+=1
    else:
        A[n]=1
print(A)
