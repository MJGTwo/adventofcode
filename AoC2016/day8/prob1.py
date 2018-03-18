"""
Author: Michael Gardner
Date: 12/08/16
Advent of Code
adventofcode.com
problem 1
"""

def parse(name):
    ''' reads input into program'''
    return [line.strip() for line in open(name)]


if __name__ == "__main__":
    print "Hello AoC!"
    DATA = parse("input1.txt")
    #print DATA
    table = []
    for i in range(6):
        row = []
        for j in range(50):
            row.append(".")
        table.append(row)
    for i in range(6):
        print table[i]
    count = 0
    for line in DATA:
        line = line.split(" ")
        print line
        if len(line) == 2:
            A,B = line[1].split("x")
            A = int(A)
            B = int(B)
            for i in range(B):
                for j in range(A):
                    table[i][j] = "#"
        else:

            if line[2].split("=")[0]=="x":
                loc = line[2].split("=")
                loc = int(loc[1])
                move = int(line[4])
                temp = list()
                for i in range(6):
                    temp.append(table[i][loc])
                for i in range(6):
                    table[i][loc] = temp[(i-move) % 6]
            else:
                loc = line[2].split("=")
                loc = int(loc[1])
                move = int(line[4])
                temp = list()
                for i in range(50):
                    temp.append(table[loc][i])
                for i in range(50):
                    table[loc][i] = temp[(i-move) % 50]


        for i in range(len(table)):
            print table[i]
        print "_____________"

    sum =0
    for i in range(len(table)):
        temp = " ".join(table[i])
        sum += temp.count("#")
        #print temp
    print sum
