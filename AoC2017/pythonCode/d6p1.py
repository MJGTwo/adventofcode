from collections import Counter

memory = [5,1,10,0,1,7,13,14,3,12,8,10,7,12,0,6]

def findMaxIndex(l):
    i =0
    for j in range(len(l)):
        if l[i] < l[j]:
            i =j
    return i

def distributeMem(l,val,i):
    i = (i+1)%len(l)
    #print(l)
    while val > 0:
        l[i] += 1
        val -= 1
        i = (i+1)%len(l)
    #print(l)
    return l

def storeState(l,states):
    l = convertToStr(l)
    states[l] += 1
    if states[l] >= 2:
        return (states, True)
    else:
        return states, False

def convertToStr(l):
    l = list(map(str,l))
    return ','.join(l)


if __name__ == "__main__":
    states = Counter()
    cycles = 0
    done = False
    states[convertToStr(memory)] = 0
    while not done:
        i = findMaxIndex(memory)
        largest = memory[i]
        memory[i] = 0
        memory = distributeMem(memory,largest,i)
        states, done = storeState(memory,states)
        cycles += 1
    print(cycles)
    start = convertToStr(memory)
    done = False
    cycles = 0
    finish = ''
    while start != convertToStr(finish):
        i = findMaxIndex(memory)
        largest = memory[i]
        memory[i] = 0
        memory = distributeMem(memory,largest,i)
        finish = memory
        cycles += 1
    print(cycles)
