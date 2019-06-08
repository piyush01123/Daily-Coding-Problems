print("buggy output")
def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f()


print("method 1")
def print_i(i):
    print(i)

def make_functions(func, args):
    for arg in args:
        func(arg)

make_functions(print_i, [1, 2, 3])



print("method 2")
def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i(i):
            print(i)
        flist.append([print_i, i])

    return flist

functions = make_functions()
print(functions)
for f, i in functions:
    f(i)
