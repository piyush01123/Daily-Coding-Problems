---
layout: post
title: "Maximum stock profit"
categories: misc
---

This problem was asked by Facebook.

Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.


My Solution(Python):
```

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
```
