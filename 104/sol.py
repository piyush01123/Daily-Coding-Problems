
class ListNode:
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev
        self.head = self

    def add_to_list(self, val):
        new_node = ListNode(data=val)
        self.head.next = new_node
        new_node.prev = self.head
        self.head = self.head.next

    def print_llF(self):
        curr = self.next
        while curr is not None:
            print(curr.prev, curr.data, curr.next)
            curr = curr.next

    def print_llB(self):
        curr = self.head
        while curr.prev is not None:
            print(curr.prev, curr.data, curr.next)
            curr = curr.prev


def isPalindrome(root):
    curr1 = root.next
    curr2 = root.head
    while curr1 is not None and curr2.prev is not None:
        # print(curr1.data, curr2.data, curr1.next, curr2.prev)
        if curr1.data != curr2.data:
            return False
        curr1 = curr1.next
        curr2 = curr2.prev
    return True


def main1():
    print('Test with Doubly Linked List')
    ll = ListNode('*')
    for i in [1, 4, 3, 4, 1]:
        ll.add_to_list(i)
    # ll.print_llF()
    # ll.print_llB()
    print(isPalindrome(ll))

    ll = ListNode('*')
    for i in [1, 4]:
        ll.add_to_list(i)
    print(isPalindrome(ll))



class ListNodeSL:
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.head = self

    def add_to_list(self, val):
        new_node = ListNodeSL(data=val)
        self.head.next = new_node
        self.head = self.head.next


def isPalindrome(root):
    stack = []
    curr = root.next
    while curr is not None:
        stack.append(curr.data)
        curr = curr.next
    while len(stack)>1:
        if stack.pop(0) != stack.pop():
            return False
    return True


def main2():
    print('Test with Singly Linked List')
    ll = ListNodeSL('*')
    for i in [1, 4, 3, 4, 1]:
        ll.add_to_list(i)
    print(isPalindrome(ll))

    ll = ListNodeSL('*')
    for i in [1, 4]:
        ll.add_to_list(i)
    print(isPalindrome(ll))


if __name__=='__main__':
    main1()
    main2()
