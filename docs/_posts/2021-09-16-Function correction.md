---
layout: post
title: "Function correction"
categories: misc
---

This problem was asked by Dropbox.

What does the below code snippet print out? How can we fix the anonymous functions to behave as we'd expect?
```
functions = []
for i in range(10):
    functions.append(lambda : i)

for f in functions:
    print(f())
```


My Solution(Python):
```

# Given code snippet prints out 9 10 times).
# Probably we wanted to print 0 to 9 integers.
# The reason it does not work is that the lambda function returns i; so if the value of i changes, so does the lambda function change.

functions = []
for i in range(10):
    functions.append(lambda: i)

for i, f in enumerate(functions):
    print(f())

#or

functions = []
for i in range(10):
    functions.append(lambda i: i)

for i, f in enumerate(functions):
    print(f(i))
```
