class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        S = set()
        for num in nums:
            S.add(num)
        for i in range(1, len(nums)+1):
            if i not in S:
                return i
        return len(nums) + 1
