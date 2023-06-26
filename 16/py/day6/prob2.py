"""
Author: Michael Gardner
Date: 12/06/16
Advent of Code
adventofcode.com
problem 2
"""
import prob1
from collections import defaultdict


if __name__ == "__main__":
    print "Hello AoC!"
    INFO = prob1.parse("input1.txt")
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
        print min(inverse)[1]
