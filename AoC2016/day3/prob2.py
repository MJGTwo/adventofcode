"""
Author: Michael Gardner
Date: 12/03/16
Advent of Code
adventofcode.com
problem 2
"""

from prob1 import *

def secondParse(l):
    result = list()

    for i in range(0,len(l)-2,3):
        for j in range(3):
            temp1 = list()
            temp1.append(l[i][j])
            temp1.append(l[i+1][j])
            temp1.append(l[i+2][j])
            result.append(temp1)
    return result



if __name__ == "__main__":
    info2 = secondParse([[int(x) for x in line.split()] for line in open("input1.txt")])
    answer = 0
    for tri in info2:
        if test(tri):
            answer += 1
    print answer
