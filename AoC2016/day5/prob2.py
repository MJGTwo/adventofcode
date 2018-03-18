"""
Author: Michael Gardner
Date: 12/05/16
Advent of Code
adventofcode.com
problem 2
"""

import sys
import md5
m = md5.new('abc3231929')



if __name__ == "__main__":
    print "hello AoC!"
    print m.hexdigest()
    pw = "cxdnnyjw"
    result = ['','','','','','','','','','','','','']
    count = set([0,1,2,3,4,5,6,7])
    num  =0
    while len(count) > 0:
        m = md5.new(pw+str(num)).hexdigest()
        if (m[:5]=="00000"):
            if (m[5].isdigit()):
                if (int(m[5]) < 8):
                    if int(m[5]) in count:
                        result[int(m[5])]=m[6]
                        count.remove(int(m[5]))
                    print num
        num += 1
    print result
