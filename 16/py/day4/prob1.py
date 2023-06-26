"""
Author: Michael Gardner
Date: 12/04/16
Advent of Code
adventofcode.com
problem 1
"""


def input(name):
    return [x.strip().split("[") for x in open(name)]

def parse(lines):
    for i in range(len(lines)):
        line = lines[i]
        line[1] = line[1].strip(']')
        line[0] = line[0].split("-")
        num =  line[0][-1]
        line[0].remove(num)
        line[0]=''.join(line[0])
        lines[i] = [line[0],line[1],num,line[0].split()]
    return lines


def solution(info):
    success = list()
    total = 0
    for i in range(len(info)):
        good = True
        checksum = info[i][1]
        room = info[i][0]
        for let in checksum:
            if let not in room:
                good = False
        if good:
            for let in room:
                if let not in checksum:
                    cs = [room.count(checksum[0]),room.count(checksum[1]),room.count(checksum[2]),room.count(checksum[3]),room.count(checksum[4])]
                    if room.count(let) > min(cs):
                        good = False
            if good:
                success.append(info[i])
    for i in range(len(success)):
        if len(success[i][2]) > 0:
            total += int(success[i][2])
    return total, success
if __name__ == "__main__":
    raw_data= input("input1.txt")
    data = parse(raw_data)
    print solution(data)[0]
