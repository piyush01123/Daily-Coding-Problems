
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
