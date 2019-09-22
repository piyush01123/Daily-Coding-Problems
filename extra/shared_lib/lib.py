
import ctypes

_summer = ctypes.CDLL("./libsummer.so")

def sum(numbers):
    n = len(numbers)
    _sz = ctypes.c_int(n)
    _arr = (ctypes.c_int*n)(*numbers)
    _summer.sum.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_int))
    return _summer.sum(_sz, _arr)
