import json
from pprint import pprint

f = open('input0.json','r')
f=f.read()
sum =0
neg = False
num = False
word = ""
obj = False
red = False
for let in f:
    if not red:
        if let == "{":
            obj = True
        elif let == "}":
            obj = False
        if obj and let == "red":
            red = True
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
    elif red and let == "}":
        obj = False
        red = False
if (len(word) >0):
    if (neg):
        sum -= int(word)
    else:
        sum += int(word)
neg = False
word = ""
print sum
