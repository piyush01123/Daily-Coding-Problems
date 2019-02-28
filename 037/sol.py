import unittest

def powerset(s: set) -> list:
    l = list(s)
    n = len(l)
    A = [set() for _ in range(2**n)]
    for i in range(n):
        period = 2**(i+1)
        j = 1
        while j<2**n:
            for k in range(j-1, (period//2)+j-1):
                A[k].add(l[i])
            j+=period
    return A

class testClass(unittest.TestCase):
    def testPowerset(self):
        s = {1, 2, 3}
        p = [{1, 2, 3}, {2, 3}, {1, 3}, {3}, {1, 2}, {2}, {1}, set()]
        q = powerset(s)
        self.assertEqual(p, q)

if __name__=='__main__':
    unittest.main()
