---
layout: post
title: "Time-based Map"
categories: misc
---

This problem was asked by Stripe.

Write a map implementation with a get function that lets you retrieve the value of a key at a particular time.

It should contain the following methods:
- `set(key, value, time)`: sets key to value for t = time.
- `get(key, time)`: gets the key at t = time.

The map should work like this. If we set a key at a particular time, it will maintain that value forever or until it gets set at a later time. In other words, when we get a key at a time, it should return the value that was set for that key set at the most recent time.

Consider the following examples:
```
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2
d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2
```


My Solution(Python):
```

class Map:
    def __init__(self):
        self.memory = dict()

    def set(self, key, value, time):
        if key not in self.memory:
            self.memory[key] = dict()
        self.memory[key][time] = value

    def get(self, key, time):
        time_vals = self.memory[key]
        if time < min(time_vals.keys()):
            return None
        return time_vals[max(t for t in time_vals.keys() if t<=time)]


def main():
    d = Map()
    d.set(1, 1, 0) # set key 1 to value 1 at time 0
    d.set(1, 2, 2) # set key 1 to value 2 at time 2
    print(d.get(1, 1)) # get key 1 at time 1 should be 1
    print(d.get(1, 3)) # get key 1 at time 3 should be 2

    d = Map()
    d.set(1, 1, 5) # set key 1 to value 1 at time 5
    print(d.get(1, 0)) # get key 1 at time 0 should be null
    print(d.get(1, 10)) # get key 1 at time 10 should be 1

    d = Map()
    d.set(1, 1, 0) # set key 1 to value 1 at time 0
    d.set(1, 2, 0) # set key 1 to value 2 at time 0
    print(d.get(1, 0)) # get key 1 at time 0 should be 2


if __name__=='__main__':
    main()
```
