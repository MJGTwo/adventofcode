"""
Author: Michael Gardner
Date: 12/05/16
Advent of Code
adventofcode.com
problem 1
"""

import sys
import md5
m = md5.new()



if __name__ == "__main__":
    print "hello AoC!"
    pw = "cxdnnyjw"
    result = ""
    count = 0
    num  =0
    while count < 8:
        m = md5.new(pw+str(num)).hexdigest()
        if (m[:5]=="00000"):
            result += m[5]
            count += 1
            print num
        num += 1
    print result
