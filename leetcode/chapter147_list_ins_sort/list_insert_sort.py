class ListNode:
    def __init__(self, data, next):
        self.data = data
        self.next = next

def ins_sort(lhead):
    dummy = ListNode(None, None)
    cur = lhead
    while cur:
        tmp = cur.next
        prev = dummy
        while prev.next is not None:
            if prev.next.data > cur:
                break
            prev = prev.next
        cur.next = prev.next
        prev.next = cur
        cur = tmp
    return dummy.next

