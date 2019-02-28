
def x_or_y(x, y, b):
    return x*b + y*(1-b)

if __name__=='__main__':
    print(x_or_y(5, 8, 1))
    print(x_or_y(5, 8, 0))
