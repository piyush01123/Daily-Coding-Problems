
def maxProfit(A: list) -> int:
    #Brute force O(N^2) solution
    n = len(A)
    max_profit = -10**3
    for i in range(n-1):
        for j in range(i+1, n):
            profit = A[j] - A[i]
            if profit > max_profit:
                max_profit = profit
    return max_profit

A = [9, 11, 8, 5, 7, 10]
print('Brute Force Solution = ', maxProfit(A))

def maxProfit(A: list) -> int:
    #Two pointers O(N) solution
    n = len(A)
    i = 0
    max_profits = list()
    while i<n:
        print('Currently starting at', A[i])
        j=i+1
        while j<n and A[j]>A[i]:
            max_profit_starting_at_i = A[j] - A[i]
            j+=1
        i=j
        max_profits.append(max_profit_starting_at_i)
        # print(max_profits)
    return max(max_profits)

A = [9, 11, 8, 5, 7, 10]
print('Two pointer solution = ', maxProfit(A))
