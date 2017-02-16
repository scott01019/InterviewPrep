from linked_list import *

def addLists(a, b):
    c = LinkedList()
    current_a = a.head
    current_b = b.head
    carry = 0
    while current_a != None and current_b != None:
        val = current_a.value + current_b.value
        c.append((val + carry) % 10)
        carry = int((val + carry) / 10)
        current_a = current_a.next
        current_b = current_b.next
    if current_a == None and current_b == None and carry != 0:
        c.append(carry)
    elif current_a != None:
        while current_a != None:
            c.append(current_a.value + carry)
            carry = 0
            current_a = current_a.next
    elif current_b != None:
        while current_b != None:
            c.append(current_b.value + carry)
            carry = 0
            current_b = current_b.next
    return c

a = LinkedList()
b = LinkedList()
a.append(9)
a.append(9)
a.append(9)
b.append(1)
b.append(1)
b.append(1)
b.append(1)
addLists(a, b).print_linked_list()
