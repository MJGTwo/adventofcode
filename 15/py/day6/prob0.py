

directions = open("input0.txt","r")
directions = directions.read()
lines = directions.split("\n")
print lines
instructions = list()
for i in range(len(lines)):
    if len(lines[i]) != 0:
        line = lines[i]
        line=line.split()
        letters = list()
        for word in line:
            if (not word.isalpha() or word == "off" or word == "on" or word == "toggle"):
                letters.append(word)
        temp = list()
        for i in range(len(letters)):
            if ("," in letters[i]):
                p = letters[i].split(",")
                tup = (int(p[0]),int(p[1]))
                temp.append(tup)
            else:
                temp.append(letters[i])
        instructions.append(temp)
print instructions

table = list()
for i in range(1000):
    row = list()
    for j in range(1000):
        row.append(False)
    table.append(row)
for instruction in instructions:
    startRow = instruction[1][0]
    endRow   = instruction[2][0]
    startCol = instruction[1][1]
    endCol   = instruction[2][1]
    if instruction[0] == "on":
        action = True
    elif instruction[0] == "off":
        action = False
    for i in range(startRow,endRow+1):
        for j in range(startCol, endCol+1):
            if instruction[0] == "toggle":
                table[i][j] = not table[i][j]
            else:
                table[i][j] = action
count =0
for i in range(1000):

    for j in range(1000):
        if table[i][j]:
            count += 1

print count
