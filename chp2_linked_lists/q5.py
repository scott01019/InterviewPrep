from linked_list import *
from linked_list_node import *


def findCorruption(linked_list):
    duplicates = set()
    current = linked_list.head
    while current != None:
        if current in duplicates:
            print(duplicates)
            return current
        else:
            duplicates.add(current)
            current = current.next
    return None

node0 = LinkedListNode("asdasd", None)
node1 = LinkedListNode("asdasd", None)
node2 = LinkedListNode("asdasd", None)
node3 = LinkedListNode("asdasd", None)
node4 = LinkedListNode("asdasd", None)
node5 = LinkedListNode("asdasd", None)
node6 = LinkedListNode("asdasd", None)
node7 = LinkedListNode("asdasd", None)
node8 = LinkedListNode("asdasd", None)
node9 = LinkedListNode("asdasd", None)

a = LinkedList()
a.appendNode(node0)
a.appendNode(node2)
a.appendNode(node1)
a.appendNode(node3)
a.appendNode(node4)
a.appendNode(node3)
print(findCorruption(a).value)
