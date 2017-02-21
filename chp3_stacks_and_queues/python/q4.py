class Towers:
    def __init__(self, disks):
        self.peg0 = []
        self.peg1 = []
        self.peg2 = []
        for i in range(disks, 0, -1):
            self.peg0.append(i)

    def print_towers(self):
        print(self.peg0)
        print(self.peg1)
        print(self.peg2)
        print("")

    def move(self, src, dest):
        i = src.pop()
        dest.append(i)
        self.print_towers()

    def solve(self, disk, src, dest, buf):
        if disk > 0:
            self.solve(disk - 1, src, buf, dest)
            self.move(src, dest)
            self.solve(disk - 1, buf, dest, src)

n = 5
a = Towers(n)
a.print_towers()
a.solve(n, a.peg0, a.peg2, a.peg1)
a.print_towers()
