from linked_list_node import *

class LinkedList(object):
    def __init__(self):
        self.head = None

    def append(self, value):
        if self.head == None:
            self.head = LinkedListNode(value, None)
        else:
            current = self.head
            while current.next != None:
                current = current.next
            current.next = LinkedListNode(value, None)

    def delete(self, value):
        if self.head != None and self.head.value == value:
            self.head = self.head.next
        else:
            current = self.head
            while current.next != None and current.next.value != value:
                current = current.next
            if current.next != None and current.next.value == value:
                current.next = current.next.next

    def appendNode(self, node):
        if self.head == None:
            self.head = node
        else:
            current = self.head
            while current.next != None:
                current = current.next
            current.next = node

    def print_linked_list(self):
        current = self.head
        while current != None:
            print(current)
            current = current.next
        print()

