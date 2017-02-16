
class Tower(object):
    def __init__(self, disks):
        self.num_disks = disks
        self.peg0 = []
        self.peg1 = []
        self.peg2 = []
        for i in range(disks, 0, -1):
            self.peg0.append(i)

    def move(self, pegA, pegB):
        if len(pegB) == 0:
            pegB.append(pegA.pop())
        else:
            diskB = pegB.pop()
            diskA = pegA.pop()
            if diskB > diskA:
                pegB.append(diskB)
                pegB.append(diskA)
            else:
                pegB.append(diskB)
                pegA.append(diskA)

    def solve(self, source, dest, spare):
        if source.pop() == 1:
            source.append(1)
            self.move(source, dest)
        else:
            self.solve(source, spare, dest)
            self.move(source, dest)
            self.solve(spare, dest, source)

    def print_tower(self):
        print(self.peg0)
        print(self.peg1)
        print(self.peg2)
        print("")

a = Tower(10)
a.print_tower()
a.solve(a.peg0, a.peg2, a.peg1)
a.print_tower()

