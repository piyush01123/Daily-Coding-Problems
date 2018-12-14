class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # A = [1, 1]
        # for i in range(2, n+1):
        #     A.append(A[i-2] + A[i-1])
        # return A[n]

        if n==1:
            return 1
        a=1
        b=1
        for i in range(2, n+1):
            c=a+b
            a=b
            b=c
        return c
        
