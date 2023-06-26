def test(l):
    return 1 if max(l) <sum(l) -max(l) else 0
if __name__ == "__main__":
    print sum([test(tri) for tri in [[int(x) for x in line.split()] for line in open("input1.txt")]])
