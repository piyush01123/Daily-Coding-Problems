
"""
LRU Cache Implementation
"""

import time

class Cache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.memory = {}
        self.last_access = {}

    def set(self, key, value):
        if len(self.memory)>=self.capacity:
            to_delete = min(self.last_access.items(), key=lambda kv: kv[1])[0]
            del self.memory[to_delete]
            del self.last_access[to_delete]
        self.memory[key] = value
        self.last_access[key] = time.time()

    def get(self, key):
        if key not in self.memory.keys():
            return
        self.last_access[key] = time.time()
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
