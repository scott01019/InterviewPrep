from linked_list import *
from linked_list_node import *

def deteleNodeFromLinkedList(linked_list, node):
    if linked_list.head != None:
        current = linked_list.head
        if current == node:
            linked_list.head = current.next
        else:
            while current != None and current.next != node:
                current = current.next
            if current.next == node:
                current.next = current.next.next

a = LinkedList()
a.append(0)
a.append(1)
a.append(2)
a.append(3)
a.append(4)
a.append(0)
a.append(1)
a.append(2)
a.append(3)
a.append(4)
a.append(0)
a.append(2)
deteleNodeFromLinkedList(a, a.head.next.next.next.next.next)
a.print_linked_list()
