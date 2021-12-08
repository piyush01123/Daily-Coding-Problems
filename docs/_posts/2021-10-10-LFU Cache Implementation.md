---
layout: post
title: "LFU Cache Implementation"
categories: misc
---

This problem was asked by Google.

Implement an LFU (Least Frequently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

`set(key, value)`: sets key to value. If there are already n items in the cache and we are adding a new item, then it should also remove the least frequently used item. If there is a tie, then the least recently used key should be removed.

`get(key):` gets the value at key. If no such key exists, return null.


My Solution(Python):
```

"""
Since we have to repeatedly compute the key with minimum accesses, storing the number of accesses in heap instead of hash table seems like a good idea for a real-life system.
"""

class Cache:
    def __init__(self, cache_size):
        self.cache_size = cache_size
        self.memory = dict()
        self.accesses = dict()
    def set(self, key, value):
        if len(self.memory)>=self.cache_size:
            print('memory exceeded')
            self.accesses_rev = {v: k for k, v in self.accesses.items()}
            to_delete = self.accesses_rev[min(self.accesses_rev)]
            del self.memory[to_delete]
            del self.accesses[to_delete]
        self.memory[key] = value
        self.accesses[key] = 0
    def get(self, key):
        if key not in self.memory:
            return None
        if key not in self.accesses:
            self.accesses[key] = 1
        else:
            self.accesses[key]+=1
        return self.memory[key]


if __name__=='__main__':
    cache = Cache(5)
    cache.set('x', 0)
    cache.set('y', 1)
    cache.set('z', 2)
    cache.set('v', 3)
    cache.set('w', 4)
    cache.set('u', 5) #removes w as all 5 have 0 accesses

    cache.get('x')
    cache.get('u')
    cache.get('z')
    cache.get('v')
    cache.set('p', 8) #removes y as all except y have 1 access, y has 0
    cache.get('non-existent')
```
