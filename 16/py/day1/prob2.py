"""
Author: Michael Gardner
Date: 12/01/16
Advent of Code
adventofcode.com
problem 2
"""
locations = set()
old = 0
flag = True

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

def doubles(mov,loc,j,dir):
	i =0
	global flag
	global old
	global locations
	while i < mov and flag:
		loc[j] += dir
		i += 1
		locations.add(tuple(loc))
		if old == len(locations):
			print loc
			flag = False
		old = len(locations)
	return loc



def move(loc,dir,mov):
	global locations
	global old
	global flag
	temp = dir % 2
	i = 0
	if dir < 2:
		loc = doubles(mov,loc,temp,1)
	else:
		loc = doubles(mov,loc,temp,-1)
	return loc

if __name__ == "__main__":
	instructions = parse("input1.txt")
	location = [0,0]
	direction = 0

	locations.add(tuple(location))
	old = 1
	for i in range(len(instructions)):
		d = instructions[i][0]
		m = instructions[i][1]
		#print direction, location, d, m

		direction = turn(direction,d)
		location = move(location,direction,m)
		locations.add(tuple(location))
	#print direction, location, d, m
	for i in range(len(location)):
		location[i] = abs(location[i])
	print sum(location)
