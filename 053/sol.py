
class Queue(list):
    def __init__(self):
        super().__init__()

    def enqueue(self, element):
        self.append(element)

    def dequeue(self):
        return self.pop(0)


def main():
    queue = Queue()
    queue.enqueue(7)
    queue.enqueue(9)
    queue.enqueue(10)
    out = queue.dequeue()
    print(out, queue)


if __name__=='__main__':
    main()
