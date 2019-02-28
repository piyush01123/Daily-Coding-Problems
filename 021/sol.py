def classRoomSchedule(classes):
    """
    :type classes: List[tuples(start, end)]
    :rtype: int
    """
    N = len(classes)
    if N==0:
        return 1
    if N==1:
        return 1
    start_times = [c[0] for c in classes]
    end_times = [c[1] for c in classes]
    start_times.sort()
    end_times.sort()
    i = 1
    j = 0
    num_classes = 1
    res = 1
    while i < N and j < N:
        if start_times[i] < end_times[j]:
            num_classes+=1
            if num_classes > res:
                res = num_classes
            i+=1
        else:
            num_classes-=1
            j+=1
    return res

import unittest
class TestClass(unittest.TestCase):
    def runTest(self):
        classes = [(30, 75), (0, 50), (60, 150)]
        self.assertEqual(classRoomSchedule(classes), 2)


if __name__=='__main__':
    unittest.main()
