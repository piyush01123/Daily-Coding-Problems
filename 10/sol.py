def jobScheduler(n):
    def inner(func):
        def wrapper(*args, **kwargs):
            import time
            print('start waiting')
            time.sleep(n/1000)
            print('stop waiting')
            rv = func(*args, **kwargs)
            return rv
        return wrapper
    return inner



if __name__=='__main__':
    import time

    @jobScheduler(2000)
    def add(*args):
        print('func called')
        return sum(args)

    tit = time.time()
    add(5, 10, 2)
    print('Ran function after %f seconds' %(time.time() - tit))
