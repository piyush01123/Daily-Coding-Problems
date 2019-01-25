import time

#timer
def timer(func):
    def f(*args, **kwargs):
        before = time.time()
        rv = func(*args, **kwargs)
        after = time.time()
        print('%s ran in %s seconds' %(func.__name__, after-before))
        return rv
    return f


# Naive Algorithm
@timer
def num_primes_leq(num):
    count = 0
    for i in range(2, num+1):
        j=2
        prime=True
        while j*j<=i:
            if i%j==0:
                prime=False
                break
            j+=1
        if prime:
            # print('%d is prime' %i)
            count+=1
    return count

# Sieve of Eratosthenes
# @timer
def num_primes_leq_v2(num):
    count = 1
    primes = [2]
    # print('%d is Prime' %2)
    for i in range(3, num+1):
        for p in primes:
            if p*p>i:
                # print('%d is Prime' %i)
                primes.append(i)
                count += 1
                break
            if i%p==0:
                # print('%d has prime factor %d' %(i, p))
                break
    return count

@timer
def check_timer():
    time.sleep(2)

@timer
def graph_num_primes(N):
    import matplotlib.pyplot as plt
    num_primes = []
    for i in range(2, N+1):
        # print('Doing', i)
        num_primes.append(num_primes_leq_v2(i))
    plt.figure(figsize=(10, 6))
    plt.plot(list(range(2, N+1)), num_primes, c='b')
    plt.xlabel('N')
    plt.ylabel('Primes less than or equal to N')
    plt.grid(True)
    plt.savefig('num_primes_leq_{}.jpg'.format(N))

def main():
    # check_timer()
    print('Answer = ', num_primes_leq(10**6))
    print('Answer = ', num_primes_leq_v2(10**6))
    for N in range(1, 5):
        print('N=', N)
        graph_num_primes(10**N)

if __name__=='__main__':
    main()
