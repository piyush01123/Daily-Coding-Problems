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
 
