"""
Author: Michael Gardner
Date: 12/02/16
Advent of Code
adventofcode.com
problem 2
"""

from prob1 import *





class SuperKeypad(Keypad):

    def __init__(self):
        Keypad.__init__(self)
        self.line = '-'*11

        self.keys = [
            ["_", "_", 1, "_", "_"],
            ["_", 2, 3, 4, "_"],
            [5, 6, 7, 8, 9],
            ["_", 'A', 'B', 'C', "_"],
            ["_", "_", 'D', "_", "_"]
                        ]
        self.max = len(self.keys)
    def convert(self,letter):
        return super(SuperKeypad,self).convert(letter)
    def code(self,c):
        current = [2,0]
        for let in c:
            step = self.convert(let)
            possibleAnswer = [current[0]+step[0], current[1]+step[1]]
            if possibleAnswer[0] > -1 \
            and possibleAnswer[0] < self.max \
            and possibleAnswer[1] > -1 \
            and possibleAnswer[1] < self.max \
            and self.keys[possibleAnswer[0]][possibleAnswer[1]] != "_":
                current = possibleAnswer
        return self.keys[current[0]][current[1]]
if __name__ == "__main__":
    codes = parse("input1.txt")
    keypad = SuperKeypad()
    print keypad
    solution = str()
    for code in codes:
        solution += str(keypad.code(code))
    print solution
