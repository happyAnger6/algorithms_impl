import random

class ListNode:
    def __init__(self, data, next):
        self.data = data
        self.next = next

    def __str__(self):
        s = '%d' % self.data
        if self.next:
            s = s + '--->' + str(self.next)
        return s


def gen_list(n):
    dummy = ListNode(None, None)
    tail = dummy
    for i in sorted([random.randrange(1, 100) for _ in range(n)]):
        new_node = ListNode(i, None)
        tail.next = new_node
        tail = new_node
    return dummy.next

def merge_two_sorted_lists(l1, l2):
    dummy = ListNode(None, None)
    tail = dummy
    while l1 is not None and l2 is not None:
        cur = None
        if l1.data < l2.data:
            cur = l1
            l1 = l1.next
        else:
            cur = l2
            l2 = l2.next

        tail.next = cur
        tail = cur

    if l1 is not None:
        tail.next = l1

    if l2 is not None:
        tail.next = l2

    return dummy.next

if __name__ == "__main__":
    l1 = gen_list(5)
    l2 = gen_list(5)
    print(l1, l2)
    print(merge_two_sorted_lists(l1, l2))
    l1 = gen_list(4)
    l2 = None
    print(l1, l2)
    print(merge_two_sorted_lists(l1, l2))






