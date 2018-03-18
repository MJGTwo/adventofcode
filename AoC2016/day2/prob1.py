"""
Author: Michael Gardner
Date: 12/02/16
Advent of Code
adventofcode.com
problem 1
"""


def parse(name):
    f = open(name)
    data = f.read()
    data = data.split()
    return data

class Keypad(object):
    def __init__(self):
        self.keys = list()
        self.line = '-'*7
        num = 0
        while num < 10:
            if num % 3 == 0:
                row = list()
            num += 1
            row.append(num)
            if len(row) == 3:
                self.keys.append(row)
    def __str__(self):
        statement = self.line + "\n"
        for i in range(len(self.keys)):
            statement += "|"
            for j in range(len(self.keys[i])):
                statement+= str(self.keys[i][j])
                statement += "|"
            statement += "\n"
            statement += self.line + "\n"
        return statement

    def convert(self,letter):
        result = list()
        if letter == "U":
            result = [-1, 0]
        elif letter == "D":
            result = [1, 0]
        elif letter == "R":
            result = [0, 1]
        elif letter == "L":
            result = [0, -1]
        return result

    def code(self,c):
        current = [1,1]
        for let in c:
            step = self.convert(let)
            possibleAnswer = [current[0]+step[0],current[1]+step[1]]
            #print possibleAnswer
            if possibleAnswer[0] > -1 and possibleAnswer[0] < 3 and possibleAnswer[1] > -1 and possibleAnswer[1] < 3:
                current = possibleAnswer
            #print current
        return self.keys[current[0]][current[1]]


if __name__ == "__main__":
    codes = parse("input1.txt")
    keypad = Keypad()
    solution = str()
    for code in codes:
        solution += str(keypad.code(code))
    print solution
