"""
Author: Michael Gardner
Date: 12/13/16
Advent of Code
adventofcode.com
problem 1
"""
import copy

maxcount = 1000
def reader(name):
    return [line.strip() for line in open(name)]

def parse(data):
    return data

def wallorspace(x,y,input):
    num = x*x + 3*x + 2*x*y + y + y*y + input
    num = "{0:b}".format(num)
    onecount = num.count("1")
    if onecount % 2 ==0:
        return "."
    else:
        return "#"

def condition1(l):
    result = list()
    #print l
    for i in l:
        if i != -1:
            result.append(i)
    return result

def convert(table):
    count =0
    for i in range(len(table)):
        count += table[i].count("O")
    return count

def findpath(x,y,floor,goal,counter,xmax,ymax):
    #print "  0123456789"
    #for i in range(100):
    #    print i,
    #    print "".join(floor[i])
    results = list()
    temp = list()
    global maxcount
    #print x,y,counter
    if x < 0 or y < 0 or y > 100 or x > 100:
        #print "error 0"
        return [-1]
    elif floor[y][x] == "#" or floor[y][x] == "O":
        #print "error 1"
        return [-1]
    elif floor[y][x] == "." and goal[1] ==x and goal[0] == y:
        floor[y][x] = "O"
        print "success",counter
        maxcount = counter
        for i in floor:
            print "".join(i)
        return floor
    elif counter < maxcount:
        floor[y][x] = "O"
        if (x-1) > 0:
            temp += condition1(findpath(x-1,y,copy.deepcopy(floor),goal,counter+1,xmax,ymax))
        if (y-1) > 0:
            temp += condition1(findpath(x,y-1,copy.deepcopy(floor),goal,counter+1,xmax,ymax))
        if (x+1) <xmax:
            temp += condition1(findpath(x+1,y,copy.deepcopy(floor),goal,counter+1,xmax,ymax))
        if (y+1) < ymax:
            temp += condition1(findpath(x,y+1,copy.deepcopy(floor),goal,counter+1,xmax,ymax))
        results += temp
    else:
        return [-1]
    return results

if __name__ == "__main__":
    print "Hello, AoC!"
    f= reader("input1.txt")
    floor = list()
    for i in range(50):
        row = list()
        for j in range(50):
            row.append(wallorspace(j,i,1350))
        floor.append(row)
        print ''.join(row)
    results = findpath(1, 1, floor, (39,31), 0, 50, 50)
    results = [results[x:x+50] for x in xrange(0, len(results), 50)]
    resultsnum = [convert(table) for table in results]

    print resultsnum
