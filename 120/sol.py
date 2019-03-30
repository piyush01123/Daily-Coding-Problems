
class Singleton(object):
    """
    Simple Singleton class
    """
    _num_instances = 0
    _singleton_instance = None

    def __new__(cls):
        if Singleton._num_instances==0:
            print("Instance created")
            Singleton._num_instances += 1
            return super().__new__(cls)
        else:
            raise Exception("This is a singleton class")

    def __init__(self):
        print("Initializing")
        #this is not really required, but it's a good practice to store the only Singleton object somewhere, so you can retrieve it.
        Singleton._singleton_instance = self

    @staticmethod
    def getInstance():
        return Singleton._singleton_instance


def test():
    # Usage:
    s = Singleton() #prints Instance created
    t = Singleton() #raises Exception
    u = Singleton.getInstance() #returns the "s" instace



class SingleTon(object):
    """
    Twisted SingleTon class as the solution of the problem
    """
    _num_instances = 0
    _retrievals = 0
    _instances = {1: None, 2: None}

    def __new__(cls):
        if SingleTon._num_instances<2:
            SingleTon._num_instances += 1
            return super().__new__(cls)
        else:
            raise Exception("This is a twisted singleton class")

    def __init__(self):
        SingleTon._instances[SingleTon._num_instances] = self

    @staticmethod
    def getInstance():
        SingleTon._retrievals += 1
        return SingleTon._instances[SingleTon._retrievals%2 +1]


def main():
    # Usage
    print(SingleTon())
    # <__main__.SingleTon object at 0x10b4bf5f8>

    print(SingleTon())
    # <__main__.SingleTon object at 0x10b4bf710>

    # print(SingleTon())
    # Exception: This is a twisted singleton class

    print(SingleTon.getInstance())
    # <__main__.SingleTon object at 0x10b4bf5f8>

    print(SingleTon.getInstance())
    # <__main__.SingleTon object at 0x10b4bf710>



if __name__=='__main__':
    main()
