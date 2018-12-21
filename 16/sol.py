import string

class OrderLog(list):
    def __init__(self, N):
        super().__init__()
        self.maxLength = N
        self.length = 0
    def record(self, order_id):
        self.append(order_id)
        self.length += 1
        if self.length > self.maxLength:
            self = self[-self.maxLength:]
        print('current log = ', self)
    def get_last(self, i):
        return self[-i]

myLog = OrderLog(10)
[myLog.record(l) for l in string.ascii_lowercase]
print(myLog.get_last(2), myLog.get_last(5), myLog.get_last(1))
