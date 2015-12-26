import json
from pprint import pprint

f = open('input0.json','r')
f=f.read()
sum =0
neg = False
num = False
word = ""
for let in f:
    if (let.isdigit()):
        word += let
    elif (let == '-'):
        neg = True
    else:
        if (len(word) >0):
            if (neg):
                sum -= int(word)
            else:
                sum += int(word)
        neg = False
        word = ""
if (len(word) >0):
    if (neg):
        sum -= int(word)
    else:
        sum += int(word)
neg = False
word = ""
print sum
