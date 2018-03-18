"""
Author: Michael Gardner
Date: 12/07/16
Advent of Code
adventofcode.com
problem 2
"""

def parse(name):
    return [line.strip() for line in open(name)]


def ABA(string):
    N = len(string)
    abas = set([])
    for i in range(N-2):
        if string[i] == string[i+2] and string[i] != string[i+1]:
            abas.add((string[i], string[i+1]))
    return abas

def BAB(string):
    return set([word[::-1] for word in ABA(string)])

def insideoutside(line):
    '''splits line into tuple of inside brackets and outside brackets'''
    outsideBrackets = []
    insideBrackets = []
    i = 0
    while line.find('[', i) != -1:
        j = line.find('[', i)
        outsideBrackets.append(line[i:j])
        i = line.find(']', j)
        insideBrackets.append(line[j+1:i])
        i += 1
    outsideBrackets.append(line[i:])
    return outsideBrackets, insideBrackets

def sup_tls(s):
    '''aba is all pairs that contain two 'a's and one 'b'
    bab is all pairs that contain two 'b's and one 'a' and
    match to a pair in aba'''
    outsideBrackets, insideBrackets = insideoutside(s)
    aba = set([])
    bab = set([])
    for I in insideBrackets:
        bab |= BAB(I)
    for O in outsideBrackets:
        aba |= ABA(O)
    return aba & bab

def solve(lines):
    '''Solves the problem '''
    count = 0
    for line in lines:
        if sup_tls(line):
            count += 1
    return count
if __name__ == "__main__":
    INFO = parse("input1.txt")
    print solve(INFO)
