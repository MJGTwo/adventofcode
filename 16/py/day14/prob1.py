# """
# Author: Michael Gardner
# Date: 12/15/16
# Advent of Code
# adventofcode.com
# problem 1
# """
import hashlib

def md5(string):
    m= hashlib.md5(string).hexdigest()
    #print m
    return m

class comparer(object):
    '''
    remembers self.n
     __call__() allows the class instance to be called as a function
    '''
    def __init__(self, n=3):
        self.n = n
    def __call__(self, l):
        if len(l) < self.n:
            return -1
        for i in range(len(l)-self.n+1):
            comp = set()
            for j in range(self.n):
                comp.add(l[i+j])
            if len(comp) == 1:
                return comp.pop()
        return False


if __name__ == "__main__":
    i3 = 0
    i5 = 0
    l3 = ""
    l5 = ""
    keycount = 0
    salt = "ihaygndm"
    test3 = comparer(3)
    test5 = comparer(5)
    alreadytested = dict()
    while keycount < 64:
        maybe = md5(salt+str(i3))

        l3 = test3(maybe)
        if l3 != False and l3 != -1:
            #print maybe, i3,
            i5 = i3+1
            while i5 - i3 < 1000:
                maybe2 = md5(salt+str(i5))
                l5 = test5(maybe2)
                if l5 != False and l5 != -1 and l5 == l3:
                    keycount += 1
                    print keycount
                    print maybe, i3, maybe2, i5
                    break
                i5 += 1
            #print
        i3 += 1
