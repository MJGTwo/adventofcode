"""
Author: Michael Gardner
Date: 12/03/16
Advent of Code
adventofcode.com
problem 1
"""

def parse(name):
    return [[int(x) for x in line.split()] for line in open(name)]

def test(l):
    m = max(l)
    l.remove(m)
    return 1 if m <(l[0]+l[1]) else 0

if __name__ == "__main__":
    info = parse("input1.txt")
    print sum([test(tri) for tri in info])
