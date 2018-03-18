from d1p1 import data

def parse(text):
    result = 0
    length = len(text)
    span = length//2
    for i in range(length):
        if text[i] == text[(i+span)%length]:
            result += int(text[i])
    return result

if __name__ == "__main__":
    answer = parse(data)
    print(answer)
