from linked_list import *

def nthToLast(linked_list, n):
    if linked_list.head != None:
        current = linked_list.head
        for i in range(0, n):
            if current != None:
                current = current.next
            else:
                return None
        n = linked_list.head
        while current != None:
            current = current.next
            n = n.next
        return n.value
    else:
        return None


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
print(nthToLast(a, 3))
