"""
Author: Michael Gardner
Date: 12/04/16
Advent of Code
adventofcode.com
problem 2
"""

from prob1 import *


def solution2(info):
    deciphered = []
    save = -1
    for i in range(len(info)):
        room = info[i][-1]
        idnum = info[i][2]
        tempstr = ''
        for r in room[0]:
            tempchar = chr(((((ord(r) - 97) + int(idnum)) % 26) + 97))
            tempstr = tempstr+tempchar
            if tempstr == "northpoleobjectstorage":
                save = idnum

        deciphered.append(tempstr)
    return idnum







if __name__ == "__main__":
    raw_data= input("input1.txt")
    data = parse(raw_data)
    goodrooms =  solution(data)[1]
    print solution2(goodrooms)
