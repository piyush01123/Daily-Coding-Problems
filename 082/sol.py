
from absl import app

class Reader:
    def __init__(self, file):
        self.content = open(file, 'r').read()
        self.read_char_num = 0
        self.offset = 0
        self.file = file
    def read7(self):
        x = self.read_char_num
        self.read_char_num+=7
        return self.content[x:x+7]
    def readN(self, n):
        txt = ""
        read7 = self.read7()
        txt+=read7
        while len(txt)<n and read7 != "":
            read7 = self.read7()
            txt+=read7
        self.read_char_num=self.offset+n
        self.offset+=n
        return txt[:n]


def main(argv):
    print('Testing read7')
    reader = Reader('hello.txt')
    print(reader.read7())
    print(reader.read7())
    print(reader.read7())
    print(reader.read7())
    print(reader.read7())

    print('Testing readN')
    reader = Reader('hello.txt')
    print('N=4', reader.readN(4))
    print('N=0', reader.readN(0))
    print('N=2', reader.readN(2))
    print('N=3', reader.readN(3))
    print('N=10', reader.readN(10))
    print('N=1', reader.readN(1))

    print('Testing readN')
    reader = Reader('hello.txt')
    print('N=9', reader.readN(9))
    print('N=0', reader.readN(0))
    print('N=2', reader.readN(2))
    print('N=3', reader.readN(3))

if __name__=='__main__':
    app.run(main)
