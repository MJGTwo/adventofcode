from d2p1 import findMax, findMin, parse, reader, filename
import numpy

def testNum(num):
    return num == int(num) and num != 1

def findDivis(l):
    length = len(l)
    for i in range(length):
        num1 = l[i]
        for j in range(i,length):
            num2 = l[j]
            div1 = num1 / num2
            if testNum(div1): return div1
            div2 = num2 / num1
            if testNum(div2): return div2
    return -1



if __name__ == "__main__":
    text = reader(filename)
    # data = [[5,9,2,8],[9,4,7,3],[3,8,6,5]]
    data = parse(text)
    result = sum([findDivis(line) for line in data])

    print(result)
