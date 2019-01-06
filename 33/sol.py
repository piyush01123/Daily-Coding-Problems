class runningList(list):
    def __new__(cls):
        return super().__new__(cls)
    def __init__(self):
        super().__init__()
    def insertNum(self, num):
        self.append(num)
