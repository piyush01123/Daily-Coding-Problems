
def division(a: int, b: int) -> int:
    ctr = 0
    while a>=b:
        a-=b
        ctr+=1
    return ctr

if __name__=='__main__':
    print(division(73, 7))
    print(division(121, 11))
