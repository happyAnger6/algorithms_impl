class ListNode:
    def __init__(self, data, next):
        self.data = data
        self.next = next

def merge_two_sort_lists(lists, i):
    l1 = lists[i]
    l2 = lists[i+1]
    dummy = ListNode(None)
    tail = dummy
    while l1 and l2:
        sel = None
        if l1.data < l2.data:
            sel = l1
            l1 = l1.next
        else:
            sel = l2
            l2 = l2.next
        tail.next = sel
        tail = tail.next

    if l1:
        tail.next = l1
    if l2:
        tail.next = l2

    return dummy.next

def merge_k_sort_lists(lists):
    n = len(lists)
    i = 0
    while n > 1:
        k = (n + 1) // 2
        i = 0
        while i < n//2:
            lists[i] = merge_two_sort_lists(lists[i], lists[i+k])
            i += 1
        n = k

