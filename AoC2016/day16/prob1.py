"""
Author: Michael Gardner
Date: 12/16/16
Advent of Code
adventofcode.com
problem 1
"""


# Call the data you have at this point "a".
# Make a copy of "a"; call this copy "b".
# Reverse the order of the characters in "b".
# In "b", replace all instances of 0 with 1 and all 1s with 0.
# The resulting data is "a", then a single 0, then "b".


def reader(name):
    return [line.strip() for line in open(name)]


def dragon(text):
    b = text[::-1]
    answer= ""
    for i in range(len(b)):
        print b[i]
        if b[i] == "0":
            answer += "1"
        else:
            answer += "0"
    return text + "0" + answer

def checksum(text):
    n=2
    if len(text) % 2 == 1:
        return text
    pairs= [text[i:i+n] for i in range(0, len(text), n)]
    result = ""
    while len(result) % 2 ==0:
        result = ""
        for p in pairs:
            if len(set(p)) == 1:
                result += "1"
            else:
                result += "0"
        pairs= [result[i:i+n] for i in range(0, len(result), n)]
    return result


if __name__ == "__main__":
    input = "11101000110010100"
    #input = "10000"
    length = 35651584
    print "Hello, AoC!"
    result = ""
    while len(result) < length:
        result = dragon(input)
        input = result
        print len(result)
    print checksum(result[:length])
