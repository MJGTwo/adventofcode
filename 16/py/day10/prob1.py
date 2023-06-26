"""
Author: Michael Gardner
Date: 12/12/16
Advent of Code
adventofcode.com
problem 1
"""


def reader(name):
    f= [line.strip() for line in open(name)]
    start = list()
    move = list()
    for line in f:
        if line[0] == "v":
            start.append(line)
        else:
            move.append(line)
    return (start,move)

def parse(init,mov):

    for i in range(len(init)):
        start = init[i]
        start = start.split()
        #print start
        start = [int(start[1]),int(start[5])]
        init[i]= start
    for i in range(len(mov)):
        move = mov[i]
        move = move.split(" ")
        bot = move[1]
        low = int(move[6])
        high = int(move[11])
        if move[5] == "output":
            low = low * -1
        if move[10] == "output":
            high = high * -1
        mov[i] = [bot,low,high]
    return init,mov


if __name__ == "__main__":
    data = reader("test.txt")
    print data
    data =parse(data[0],data[1])
    print data
    bots = dict()
    for info in data[0]:
        if info[1] in bots.keys():
            bots[info[1]] = (bots[info[1]],info[0])
        else:
            bots[info[1]] = info[0]
    for bot in bots.keys():
        print bot, bots[bot]
    for move in data[1]:
