class Stack(object):
    def __init__(self):
        self.size = 300
        self.stack = [None] * 300
        self.top0 = -3
        self.top1 = -2
        self.top2 = -1

    def pop0(self):
        top = self.top0
        if self.top0 >= 0:
            self.top0 -= 3
            return self.stack[top]

    def pop1(self):
        top = self.top1
        if self.top1 >= 1:
            self.top1 -= 3
            return self.stack[top]

    def pop2(self):
        top = self.top2
        if self.top2 >= 2:
            self.top2 -= 3
            return self.stack[top]

    def push0(self, val):
        self.top0 += 3
        self.stack[self.top0] = val

    def push1(self, val):
        self.top1 += 3
        self.stack[self.top1] = val

    def push2(self, val):
        self.top2 += 3
        self.stack[self.top2] = val

a = Stack()

print(a.pop0())
print(a.pop1())
print(a.pop2())

a.push0(1)
a.push0(4)
a.push0(7)
a.push0(10)

a.push1(2)
a.push1(5)
a.push1(8)
a.push1(11)

a.push2(3)
a.push2(6)
a.push2(9)
a.push2(12)

print(a.pop0())
print(a.pop0())
print(a.pop0())
print(a.pop0())
print(a.pop0())

a.push0(1)

print(a.pop0())
