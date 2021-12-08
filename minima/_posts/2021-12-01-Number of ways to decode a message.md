---
layout: post
title: "Number of ways to decode a message"
categories: misc
---

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.


My Solution(C++):
```
// A naive recursive C++ implementation to count number of decodings
// that can be formed from a given digit sequence
#include <iostream>
#include <cstring>
using namespace std;

// Given a digit sequence of length n, returns count of possible
// decodings by replacing 1 with A, 2 woth B, ... 26 with Z
int countDecoding(char *digits, int n)
{
	// base cases
	if (n == 0 || n == 1)
		return 1;

	int count = 0; // Initialize count

	// If the last digit is not 0, then last digit must add to
	// the number of words
	if (digits[n-1] > '0')
		count = countDecoding(digits, n-1);

	// If the last two digits form a number smaller than or equal to 26,
	// then consider last two digits and recur
	if (digits[n-2] == '1' || (digits[n-2] == '2' && digits[n-1] < '7') )
		count += countDecoding(digits, n-2);

	return count;
}

// Driver program to test above function
int main()
{
	char digits[] = "1234";
	int n = strlen(digits);
	cout << "Count is " << countDecoding(digits, n);
	return 0;
}
```


My Solution(Python):
```
class Solution:
    def numDecodings(self, s):
        # store helper(data, k) at memo[k]
        memo = [None]*(len(s)+1)
        print(memo)
        return self.helper(s, len(s), memo)
    def helper(self, data, k, memo):
        # k: we are looking only for last k letters of data.
        if k==0:
            return 1
        if data[len(data) - k] == '0':
            return 0
        if memo[k] != None:
            return memo[k]
        if k>=2 and int(data[len(data)-k:len(data)-k+2])<=26:
            memo[k] = self.helper(data, k-1, memo) + self.helper(data, k-2, memo)
            return memo[k]
        else:
            memo[k] = self.helper(data, k-1, memo)
            return memo[k]
 
```
