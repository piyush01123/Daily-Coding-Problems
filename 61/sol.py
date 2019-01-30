
import time

def timer(func):
    def f(*args, **kwargs):
        tit=time.time()
        res = func(*args, **kwargs)
        tat=time.time()
        print('Time taken to execute %s is %s seconds' %(func.__name__, tat-tit))
        return res
    return f

@timer
def pow(x, y):
    res=1
    while y:
        if y&1:
            res*=x
        x*=x
        y>>=1
    return res

@timer
def default_pow(x, y):
    # return x**y
    res=1
    while y:
        res*=x
        y-=1
    return res

pairs = [(7, 17), (99, 101), (1273, 71), (79, 7913)]
for base, exp in pairs:
    pow(base, exp)
    default_pow(base, exp)
