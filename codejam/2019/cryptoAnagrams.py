
import numpy as np

def firstPrimeFactor(num, N):
    # num guaranteed to be less than N
    primes = [2]
    for i in range(3, N+1):
        for p in primes:
            if p*p>i:
                if num%i==0:
                    return i
                primes.append(i)
                break
            if i%p==0:
                break

def solve(A, N, L):
    # print('SOLVE', A, N, L)
    a = firstPrimeFactor(A[0], N)
    b = A[0]//a
    #a, b are p.f of A[0] find common p.f of A[0] and A[1]
    x = 1
    while A[x]==A[0]:
        x+=1
    if x%2==1:
        if A[x]%a==0:
            f = a
        else:
            f = b
    else:
        if A[x]%a==0:
            f = b
        else:
            f = a
    nums = [A[0]//f]
    # print('First letter', nums, a, b, x)
    for i in range(1, L):
        # print(A[i-1], i, A[i], f, nums)
        nums.append(f)
        f = A[i]//f
    nums.append(f)
    # print(nums)
    s = sorted(set(nums))
    # print(len(s), 'recheck length of alphabet')
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    dic = {n: l for n, l in zip(s, alphabet)}
    return ''.join(dic[num] for num in nums)


T = int(input())
for t in range(T):
    N, L = map(int, input().split())
    A = list(map(int, input().split()))
    print("Case #%s: %s" %(t+1, solve(A, N, L)))


# N, L = 103,  31
# S = "217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053"
# A = list(map(int, S.split()))
# A = A[::-1]
# print(solve(A, N, L))
#
# N, L = 10000, 25
# S = "3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543"
# A = list(map(int, S.split()))
# A = A[::-1]
# print(solve(A, N, L))


def getPrimes(n):
    # get first n primes
    primes = [2]
    i = 2
    while len(primes)<=n:
        i += 1
        for p in primes:
            if p*p>i:
                primes.append(i)
                break
            if i%p==0:
                break
    return primes

def isPrime(n):
    primes = [2]
    i = 2
    while i*i<=n:
        i += 1
        if n%i==0:
            return False
        for p in primes:
            if p*p>i:
                primes.append(i)
                break
            if i%p==0:
                break
    return True

#
# N = 10000
# AA = getPrimes(1200)
# for _ in range(1000):
#     idx = np.random.choice(len(AA), 26, replace=False) #for 26 letters
#     nums = [AA[c] for c in idx] # to be used in dictionary
#     nums.sort()
#     alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#     dic = {n: l for n, l in zip(nums, alphabet)}
#     # word =  ''.join(l*4 for l in alphabet)
#     # word = ''.join(word[i] for i in np.random.permutation(104))
#     # print(word)
#     freq = {i: np.random.randint(1, 5) for i in range(26)}
#     nums_word = [[nums[i]]*freq[i] for i in range(26)]
#     nums_word = [i for j in nums_word for i in j]
#     nums_word = list(np.random.permutation(nums_word))
#     L = len(nums_word) - 1
#     # print('Letters in alphabet=', len(set(nums_word)), '\nLetters in word=', L+1, 'Word=', ''.join(dic[n] for n in nums_word), '\n', nums_word)
#     A = [nums_word[i]*nums_word[i+1] for i in range(L)]
#     print(''.join(dic[m] for m in nums_word))
#     print(solve(A, N, L))

    # L = np.random.randint(25, 101)
    # A = []
    # prev_id = np.random.choice(26, 1, replace=False)[0]
    # for _ in range(L):
    #     id = np.random.choice(26, 1, replace=False)[0]
    #     A.append(nums[prev_id]*nums[id])
    #     prev_id = id
    # print(solve(A, N, L))
