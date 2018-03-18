

f = open("input0.txt","r")
f= f.read()
lines = f.split('\n')
alph = dict()
for i in range(len(lines)):
    line = lines[i]
    lines[i] = line.split(" -> ")
lines.pop()
for line in lines:
    alph[line[1]]=line[0]
change = True
count = 0

answer = open("output.txt","w")

while (change):
    #print "start", count, alph['a']
    change = False
    start = alph['a']
    parse = start.split(" ")
    nextst = ""
    for i in range(len(parse)):
        word = parse[i]
        if ((word not in ["NOT","OR","AND","RSHIFT","LSHIFT","(",")"]) and (not unicode(word).isnumeric())):
            temp = "( "
            temp += alph[word]
            temp += " )"
            nextst += temp
        else:
            nextst += word
        nextst += " "
    count+=1
    print count
    nextst= nextst.strip()
    if (nextst != start):
        change = True
    alph['a'] = nextst
answer.write( alph['a'])
answer.close()
