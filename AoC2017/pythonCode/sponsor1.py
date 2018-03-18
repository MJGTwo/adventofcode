# xor(Pz0pQUI7Ch cmER8YDAEYAh4L GwEP, ↑↑↓↓←→←→BA)

def xor(a,b):
    a= tobits(a)
    b =tobits(b)
    aLen = len(a)
    bLen = len(b)
    a.reverse()
    b.reverse()
    i = 0
    result = list()
    while len(b) < len(a):
        b.append(0)
    while len(b) > len(a):
        a.append(0)
    while i < len(a):
        result.append(a[i]^b[i])
        i+=1
    print(len(result))
    result.reverse()
    print(result)
    return frombits(result)

def frombits(bits):
    chars = []
    # print('test',range(len(bits) / 8))
    for b in range(len(bits) // 8):
        byte = bits[b*8:(b+1)*8]
        chars.append(chr(int(''.join([str(bit) for bit in byte]), 2)))
    return ''.join(chars)


def tobits(s):
    result = []
    for c in s:
        bits = bin(ord(c))[2:]
        bits = '00000000'[len(bits):] + bits
        result.extend([int(b) for b in bits])
    return result

print(xor('Pz0pQUI7Ch cmER8YDAEYAh4L GwEP', '↑↑↓↓←→←→BA'))
