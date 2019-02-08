
"""Similar to 45"""

import numpy as np
import unittest
from collections import defaultdict

def rand7():
    return np.random.randint(1, 8)

def rand5():
    x, y = rand7(), rand7()
    z = 7*(x-1)+y-1 # Z is uniformly distributed in [0, 48]
    if z<=44:
        return z//9
    else:
        return rand5()

class testRandomGenerator(unittest.TestCase):
    def test_rand5(self):
        H = defaultdict(int)
        for _ in range(10**6):
            H[rand5()]+=1
        for key in H.keys():
            H[key] = round(H[key]/10**6, 2)
        self.assertDictEqual(H, {k: 0.2 for k in range(5)})

if __name__=='__main__':
    unittest.main()
