"""
Author: Michael Gardner
Date: 12/01/16
Advent of Code
adventofcode.com
problem 1
"""


def parse(name):
    f0 = open(name)
    data = f0.read()
    instructions = data.split(",")
    for i in range(len(instructions)):
        instructions[i] = instructions[i].strip()
        d = instructions[i][0]
        m = int(instructions[i][1:])
        instructions[i] = [d,m]
    return instructions

def turn(curr,dir):
	#N E S W
	#0 1 2 3
	if dir == "R":
		curr += 1
	elif dir == "L":
		curr -= 1
	curr = curr % 4
	return curr

def move(loc,dir,mov):
	temp = dir % 2
	if dir < 2:
		loc[temp] += mov
	else:
		loc[temp] -= mov
	return loc

if __name__ == "__main__":
	instructions = parse("input1.txt")
	location = [0,0]
	direction = 0
	for i in range(len(instructions)):
		d = instructions[i][0]
		m = instructions[i][1]
		#print direction, location, d, m

		direction = turn(direction,d)
		location = move(location,direction,m)
	for i in range(len(location)):
		location[i] = abs(location[i])
	print sum(location)
