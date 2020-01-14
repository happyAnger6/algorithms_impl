class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

class NodeList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add(self, data, next=None):
        n = Node(data, next)
        if self.head is None:
            self.head = n
            self.tail = n
        else:
            n.next = self.head
            self.head = n

    def add_tail(self, data, next=None):
        n = Node(data, next)
        if self.tail is None:
            self.head = n
            self.tail = n
        else:
            self.tail.next = n
            self.tail = n

    def __str__(self):
        s = ''
        n = self.head
        while n is not None:
            s += '--->%d' % (n.data)
            n = n.next
        return s

def add_two_reverse_lists(s1, s2):
    carry = 0
    num = 0
    new_list = NodeList()
    n1 = s1.head
    n2 = s2.head
    while n1 is not None or n2 is not None:
        l1, l2 = 0, 0
        if n1 is not None:
            l1 = n1.data
            n1 = n1.next
        if n2 is not None:
            l2 = n2.data
            n2 = n2.next
        num = l1 + l2 + carry
        carry = num//10
        new_list.add_tail((num%10))
    if carry:
        new_list.add_tail((carry))
    return new_list

import random
if __name__ == "__main__":
    l1 = NodeList()
    l2 = NodeList()
    for i in range(3):
        l1.add(random.randrange(10), None)
        l2.add(random.randrange(10), None)
    print(l1)
    print(l2)
    print(add_two_reverse_lists(l1, l2))

