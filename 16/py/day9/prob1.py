"""
Author: Michael Gardner
Date: 12/12/16
Advent of Code
adventofcode.com
problem 1
"""


def parse(name):
    return [line.strip() for line in open(name)]



def decompress(line):
    if '(' not in line:
        return len(line)
    ret = 0
    while '(' in line:
        ret += line.find('(')
        line = line[line.find('('):]
        marker = line[1:line.find(')')].split('x')
        line = line[line.find(')') + 1:]
        ret += len(line[:int(marker[0])]) * int(marker[1])
        line = line[int(marker[0]):]
    ret += len(line)
    return ret


if __name__ == "__main__":
    info = parse("input1.txt")
    data = ""
    for i in info:
        data += i
    print decompress(data)
