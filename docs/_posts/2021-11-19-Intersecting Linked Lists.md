---
layout: post
title: "Intersecting Linked Lists"
categories: misc
---

This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.


My Solution(Python):
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        # Solution 1
        # A = set()
        # while headA:
        #     A.add(headA)
        #     headA = headA.next
        # while headB:
        #     # print(A)
        #     if headB in A:
        #         return headB
        #     A.add(headB)
        #     headB = headB.next

        # Solution 2
        currA = headA
        currB = headB
        while currA != currB:
            if currA is None:
                currA = headB
            else:
                currA = currA.next
            if currB is None:
                currB = headA
            else:
                currB = currB.next
        return currA



        
```
