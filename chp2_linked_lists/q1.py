from linked_list import *

def deleteDuplicates(linked_list):
    if linked_list.head != None:
        duplicates = set()
        current = linked_list.head
        duplicates.add(current.value)
        while current.next != None:
            if current.next.value in duplicates:
                current.next = current.next.next
            else:
                duplicates.add(current.next.value)
                current = current.next

def deleteDuplicates2(linked_list):
    current = linked_list.head
    while current != None:
        search = current
        while search != None and search.next != None:
            if search.next.value == current.value:
                search.next = search.next.next
            search = search.next
        current = current.next
            

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
a.print_linked_list()
deleteDuplicates2(a)
a.print_linked_list()
