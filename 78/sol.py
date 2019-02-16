
import heapq

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

def mergeSortedLists(lsts: 'list(ListNode)') -> ListNode:
    if lsts is None or len(lsts)==0:
        return None
    H = []
    for i, lst in enumerate(lsts):
        heapq.heappush(H, (lst.val, i))
    merged_lst = ListNode('*')
    curr = merged_lst
    while len(H)>0:
        val, idx = heapq.heappop(H)
        curr.next = ListNode(val)
        curr = curr.next
        if lsts[idx].next is not None:
            lsts[idx] = lsts[idx].next
            heapq.heappush(H, (lsts[idx].val, idx))
    return merged_lst.next

def main():
    lst1=ListNode(1); lst1.next=ListNode(4); lst1.next.next=ListNode(5)
    lst2=ListNode(1); lst2.next=ListNode(3); lst2.next.next=ListNode(4)
    lst3=ListNode(2); lst3.next=ListNode(6);
    lst4=mergeSortedLists(lsts=[lst1, lst2, lst3])
    curr=lst4
    while curr is not None:
        print(curr.val)
        curr=curr.next

if __name__=='__main__':
    main()
