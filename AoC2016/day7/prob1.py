"""
Author: Michael Gardner
Date: 12/07/16
Advent of Code
adventofcode.com
problem 1
"""
import collections

def parse(name):
    ''' reads input into program'''
    return [line.strip() for line in open(name)]

def test(line):
    flag = False
    wait = False
    flag2 = False
    for i in range(len(line)-3):
        if not wait:
            if line[i] != "[":
                if line[i] == line[i+3] and line[i+1]==line[i+2] and line[i] != line[i+1]:
                    #print line[i],line[i+1],line[i+2], line[i+3]
                    flag = True
            else:
                wait = True
        else:
            print line[i],
            if (line[i] == line[i+3] and line[i+1]==line[i+2] and line[i] != line[i+1]):
                flag2 = True
            if line[i] == "]":
                wait = False
                print
    if not flag2 and line.count("[") == line.count("]") :
        if flag:
            print line
            return 1
        else:
            return 0
    else:
        return 0



if __name__ == "__main__":
    print "Hello AoC!"
    DATA = parse("input1.txt")
    count = 0


    for line in DATA:
        #print line
        count += test(line)
        #print "#", line
    print count
    print 'aba' & 'bab'
