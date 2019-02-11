
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
