"""
Author: Michael Gardner
Date: 12/06/16
Advent of Code
adventofcode.com
problem 2
"""

from collections import defaultdict


def parse(name):
    """parses input file"""
    return [line.strip() for line in open(name)]



if __name__ == "__main__":
    print "Hello AoC!"
    INFO = parse("input1.txt")
    TURN = list()
    for j in range(len(INFO[0])):
        row = ""
        for i in range(len(INFO)):
            row += INFO[i][j]
        TURN.append(row)
    for item in TURN:
        print item
    for row in TURN:
        d = defaultdict(int)
        for let in row:
            d[let] += 1

        inverse = [(value, key) for key, value in d.items()]
        print max(inverse)[1]
