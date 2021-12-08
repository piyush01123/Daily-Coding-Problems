---
layout: post
title: "Reverse Linked List in-place"
categories: misc
---

This problem was asked by Google.

Given the head of a singly linked list, reverse it in-place.


My Solution(Python):
```

class ListNode:
    def __init__(self, val=None):
        self.val = val
        self.next = None
        self.trav = self

    def add_to_list(self, val):
        self.trav.next = ListNode(val)
        self.trav = self.trav.next

    def printLinkedList(self):
        curr = self
        while curr is not None:
            print(curr.val)
            curr = curr.next

def createDoublyLinkedList(ll: ListNode) -> ListNode:
    curr = ll
    curr.prev = None
    while curr.next is not None:
        curr.next.prev = curr
        curr = curr.next
    print('reverse traversal')
    while curr is not None:
        print(curr.val)
        curr = curr.prev
    return ll

def reverseLinkedList(ll: ListNode) -> ListNode:
    curr = ll
    curr.prev = None
    while curr.next is not None:
        curr.next.prev = curr
        curr = curr.next
    ll_rev = curr
    while curr is not None:
        curr.next = curr.prev
        curr = curr.prev
    return ll_rev




def reverseLL(head: 'ListNode') -> 'ListNode':
    # Much cleanerc
    if head is None or head.next is None:
        return head
    curr = head
    next = curr.next
    prev = None
    while curr.next is not None:
        next = curr.next
        curr.next = prev
        prev  = curr
        curr = next
    curr.next = prev
    return curr


def test_cleaner_code():
    print('New cleaner code')
    class ListNode:
        def __init__(self, val=None):
            self.val = val
            self.next = None
    curr = ll = ListNode('*')
    for i in range(1, 10, 2):
        curr.next = ListNode(i)
        curr = curr.next
    ll = ll.next
    ll_rev = reverseLL(ll)
    curr = ll_rev
    while curr is not None:
        print(curr.val)
        curr = curr.next


if __name__=='__main__':
    ll = ListNode('*')
    # curr = ll
    # for i in range(1, 10, 2):
    #     curr.next = ListNode(i)
    #     curr = curr.next
    for i in range(1, 10, 2):
        ll.add_to_list(i)
    ll = ll.next
    ll.printLinkedList()
    # lld = createDoublyLinkedList(ll)
    ll_rev = reverseLinkedList(ll)
    ll_rev.printLinkedList()
    test_cleaner_code()
```
