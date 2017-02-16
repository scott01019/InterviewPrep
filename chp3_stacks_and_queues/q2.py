class Stack(object):
    def __init__(self):
        self.size = 300
        self.stack = [None] * self.size
        self.top = -1

    def push(self, value):
        if self.top > -1:
            self.top += 1
            if value < self.stack[self.top-1].min:
                self.stack[self.top] = StackNode(value, value)
            else:
                self.stack[self.top] = StackNode(value, self.stack[self.top-1].min)
        else:
            self.top += 1
            self.stack[self.top] = StackNode(value, value)

    def pop(self):
        if self.top > -1:
            result = self.stack[self.top]
            self.top -= 1
            return result

class StackNode(object):
    def __init__(self, value, min):
        self.value = value
        self.min = min


a = Stack()
a.push(100)
a.push(200)
a.push(300)
a.push(600)
a.push(400)
a.push(10)
a.push(1000)
a.push(5)

print(a.pop().min)
print(a.pop().min)
print(a.pop().min)
print(a.pop().min)
print(a.pop().value)
