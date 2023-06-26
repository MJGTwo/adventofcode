"""
Author: Michael Gardner
Date: 12/15/16
Advent of Code
adventofcode.com
problem 2
"""


"""
Author: Michael Gardner
Date: 12/15/16
Advent of Code
adventofcode.com
problem 1
"""

def reader(name):
    return [line.strip() for line in open(name)]

def parse(line):
    line = line.split(";")
    first = line[0].split(" ")
    second = line[1].split(" ")
    number = int(first[1].strip("#"))
    positions = int(first[3])
    time = int(second[2].strip("time=").strip(","))
    starts = int(second[7].strip("."))
    return [number, starts, time, positions]



if __name__ == "__main__":
    print "Hello, AoC!"
    data = reader("input1.txt")
    for i in range(len(data)):
        data[i] = parse(data[i])
        #print data[i]
    for t in range(0,10000000):
        flag = True
        for disk in data:
            if (disk[1]+t+ disk[0]-1) % disk[3] != 0:
                flag = False
        if flag:
            print t -1
            break
        else:
            flag = True
    print 'done'
