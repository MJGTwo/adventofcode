

steps = [0,3,0,1,-3]

def cycler(instructions):
    i = 0
    count = 0
    while i < len(instructions):
        instr = instructions[i]
        instructions[i] += 1
        #Comment line 10 and uncomment lines 12 to 15 for part 2
        # if instr >= 3:
        #     instructions[i] -= 1
        # else:
        #     instructions[i] += 1
        i += instr
        count += 1
    print(count)

def parser(filename):
    f = open(filename)
    data = f.read()
    f.close()
    data = data.split('\n')
    data = list(map(int,[val for val in data if len(val) > 0]))
    return data

if __name__ == "__main__":

    print("hi")
    steps = parser('d5.txt')
    cycler(steps)
