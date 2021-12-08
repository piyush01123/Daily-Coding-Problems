---
layout: post
title: "Pi estimation using Monte Carlo method"
categories: misc
---

This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.


My Solution(Python):
```
import numpy as np
R = 10
EXP = 6
N = 10**EXP

np.random.seed(1)
pt_x = np.random.uniform(-R, R, N)
pt_y = np.random.uniform(-R, R, N)
pts = zip(pt_x, pt_y)

ctr = 0
for i, pt in enumerate(pts):
    dist = np.linalg.norm(pt)
    if dist<=R:
        ctr+=1
    PI = 4*ctr/(i+1)

    if i%(N//100)==0:
        print(PI)

print('PI estimation by Monte Carlo = %f' %PI)
```
