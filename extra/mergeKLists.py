import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if lists is None or len(lists) == 0:
            return None
        lists = [lst for lst in lists if lst is not None]
        H = []
        for i, lst in enumerate(lists):
            heapq.heappush(H, (lst.val, i))
            lst = lst.next
        # print(H)
        mylst = ListNode(None)
        curr = mylst
        while len(H) > 0:
            # print('Heap', H)
            listval, listidx = heapq.heappop(H)
            # print(listval, listidx)
            curr.next = ListNode(listval)
            if lists[listidx].next is not None:
                lists[listidx] = lists[listidx].next
                heapq.heappush(H, (lists[listidx].val, listidx))
            curr = curr.next
        return mylst.next
