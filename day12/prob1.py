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
for i in range(len(f)-2):
    let = f[i]
    r = f[i] + f[i+1]+f[i+2]
    if not red:
        if let == "{":
            obj = True
        elif let == "}":
            obj = False
        if obj and r == "red":
            red = True
            continue
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
