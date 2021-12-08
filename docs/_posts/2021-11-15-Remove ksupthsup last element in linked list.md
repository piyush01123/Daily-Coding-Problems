---
layout: post
title: "Remove ksupthsup last element in linked list"
categories: misc
---

This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.


My Solution(Python):
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Two Pass
class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        curr = head
        count = 0
        while curr is not None:
            count+=1
            curr = curr.next
        bad_node = count-n+1
        curr = head
        ll = ListNode(None)
        trav = ll
        for enum in range(bad_node-1):
            trav.next = ListNode(curr.val)
            trav = trav.next
            curr = curr.next
        curr = curr.next
        while curr is not None:
            trav.next = ListNode(curr.val)
            trav = trav.next
            curr = curr.next
        return ll.next
```
