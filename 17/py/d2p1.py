filename = 'd2.txt'

def reader(name):
    f = open(name)
    data = f.read()
    f.close()
    return data

def parse(data):
    result = data.split('\n')
    return [list(map(int, line.split('\t'))) for line in result if len(line) > 0]

findMax = lambda mx, l: mx if len(l) == 0 else (findMax(mx,l[1:]) if mx >= l[0] else findMax(l[0],l[1:]))
findMin = lambda mn, l: mn if len(l) == 0 else (findMin(mn,l[1:]) if mn <= l[0] else findMin(l[0],l[1:]))



if __name__ == "__main__":
    text = reader(filename)
    data = parse(text)

    #print(data)
    #data = [[5,1,9,5],[7,5,3],[2,4,6,8]]
    minmax = [findMax(line[0],line)-findMin(line[0],line) for line in data]
    print(sum(minmax))
