class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next

def swap_two_nodes(head):
    if head is None or head.next is None:
        return None
    n = head.next
    head.next = swap_two_nodes(n.next)
    n.next = head

def swap_two_nodes_no_recursive(head):
    start = head
    next_start = None
    dummy = Node(None, None)
    prev_tail = dummy
    while start and start.next:
        next_start = start.next.next
        prev_tail.next = start.next
        start.next.next = start
        prev_tail = start
        start = next_start
    prev_tail.next = start
    return dummy.next
