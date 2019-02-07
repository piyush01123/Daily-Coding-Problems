
def perfectNumber(n):
    ctr=1
    num=19
    while ctr<=n:
        a, b = num//10, num%10
        num = 10*(a+1) + (b-1)
        if sum(list(map(int, str(num)))) !=10:
            continue
        print(ctr, num)
        ctr+=1

    return num

print(perfectNumber(1000))
