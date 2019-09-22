
import lib
import time

A = list(range(1, 10001))

tit = time.time()
s1 = lib.sum(A)
tat = time.time()

tit = time.time()
s2 = 0
for a in A:
    s2+=a
tat = time.time()

print(s1, tat-tit)
print(s2, tat-tit)
