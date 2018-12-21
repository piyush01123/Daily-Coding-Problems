class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        inc = nums[0]
        exc = 0
        for num in nums[1:]:
            old_inc = inc
            inc = exc + num
            exc = max(old_inc, exc)
            # print(exc, inc)
        return max(exc, inc)

if __name__=='__main__':
    print(Solution().rob([5, 1, 1, 5]))
