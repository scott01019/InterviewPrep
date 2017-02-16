class StackOfStacks(object):
    def __init__(self, capacity):
        self.top = 0
        self.capacity = capacity
        self.stacks = []
        self.stacks.append(Stack())

    def popAt(self, n):
        return self.stacks[n].pop()

    def pop(self):
        return self.stacks[self.top].pop()

    def push(self, val):
        if len(self.stacks[self.top]) == self.capacity:
            self.top += 1
            self.stacks.append(Stack())
            self.stacks[self.top].push(val)
        else:
            self.stacks[self.top].push(val)
            

class Stack(object):
    def __init__(self):
        self.stack = []

    def __len__(self):
        return len(self.stack)

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        return self.stack.pop()

a = StackOfStacks(3)
a.push(0)
a.push(0)
a.push(0)
a.push(1)
a.push(1)
a.push(1)
a.push(2)
a.push(2)
a.push(2)

print(a.pop())
print(a.pop())
print(a.popAt(1))
print(a.pop())
