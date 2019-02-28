from collections import deque
class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(nums)==0:
            return []
        if k==0:
            return nums
        deck = deque()
        for i in range(k):
            while len(deck) != 0:
                if nums[i] > nums[deck[-1]]:
                    deck.pop()
                else:
                    break
            deck.append(i)
        res = []
        for i in range(k, len(nums)):
            # print('current Deck', deck, 'at i = ', i)
            res.append(nums[deck[0]])
            if deck[0]<i-k+1:
                # print('deck[0]<i-k+1')
                deck.popleft()
            # print('current Deck', deck, 'at i = ', i)
            while len(deck) != 0:
                # make deck such that it is either empty or nums at its last
                # element is greater than current num
                if nums[i]>nums[deck[-1]]:
                    # print('we pop at i=', i)
                    deck.pop()
                else:
                    break
            # print('current Deck', deck, 'at i = ', i)
            deck.append(i)
        res.append(nums[deck[0]])
        return res
