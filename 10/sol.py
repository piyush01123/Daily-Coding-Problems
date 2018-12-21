import unittest
import time

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

class testJobScheduler(unittest.TestCase):

    @staticmethod
    @jobScheduler(2000)
    def add(*args):
        print('func called')
        return sum(args)

    def testValue(self):
        ans = self.add(5, 10, 2)
        self.assertEqual(ans, 17)

    def testFunc(self):
        tit = time.time()
        ans = self.add(5, 10, 8)
        tat = time.time()
        self.assertAlmostEqual(tat-tit, 2, places = 0)

if __name__=='__main__':
    unittest.main()
