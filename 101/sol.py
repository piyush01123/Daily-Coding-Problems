
def godbachPair(num: int) -> 'list(int)':
    if num%2==1 or num<4:
        return None
    if num==4 or num==6:
        return [num//2, num//2]
    primes = {2}
    for i in range(3, num):
        found = False
        for p in primes:
            if p*p>i:
                break
            if i%p==0:
                found = True
                break
        if found == False:
            if num-i in primes:
                return ([num-i, i])
            primes.add(i)


if __name__=='__main__':
    for num in range(4, 101, 2):
        print(num, godbachPair(num))
