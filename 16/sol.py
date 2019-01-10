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
            del self[0]
        print('current log = ', self)
    def get_last(self, i):
        if i>self.maxLength:
            raise Exception("This log can only store the last %i items" %self.maxLength)
        return self[-i]

myLog = OrderLog(10)
for l in string.ascii_lowercase:
    myLog.record(l)

print(myLog.get_last(2), myLog.get_last(5), myLog.get_last(1))
