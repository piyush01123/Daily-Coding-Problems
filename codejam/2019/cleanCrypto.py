
def firstPrimeFactor(num, N):
    if num%2==0:
        return 2
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
    a = firstPrimeFactor(A[0], N)
    # print(A[0], a)
    b = A[0]//a
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
    for i in range(1, L):
        nums.append(f)
        f = A[i]//f
    nums.append(f)
    s = sorted(set(nums))
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    dic = {n: l for n, l in zip(s, alphabet)}
    return ''.join(dic[num] for num in nums)

def main():
    T = int(input())
    for t in range(T):
        N, L = list(map(int, input().split()))
        A = list(map(int, input().split()))
        print("Case #%s: %s" %(t+1, solve(A, N, L)))


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

def test():
    import numpy as np
    N = 10000
    AA = getPrimes(1200)
    trues = []
    for _ in range(100000):
        idx = np.random.choice(len(AA), 26, replace=False) #for 26 letters
        nums = [AA[c] for c in idx] # to be used in dictionary
        nums.sort()
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        dic = {n: l for n, l in zip(nums, alphabet)}
        freq = {i: np.random.randint(1, 5) for i in range(26)}
        nums_word = [[nums[i]]*freq[i] for i in range(26)]
        nums_word = [i for j in nums_word for i in j]
        nums_word = list(np.random.permutation(nums_word))
        L = len(nums_word) - 1
        A = [nums_word[i]*nums_word[i+1] for i in range(L)]
        ques = ''.join(dic[m] for m in nums_word)
        ans = solve(A, N, L)
        print(ques+'\n'+ans)
        trues.append(ques==ans)
    print(all(trues))

if __name__=='__main__':
    test()
    # main()
