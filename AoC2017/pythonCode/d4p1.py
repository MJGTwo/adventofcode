
filename = 'd4.txt'

def reader(filename):
    with open(filename) as f:
        data = f.read()
    return data

def parser(data):
     return [val.split(' ') for val in data.split('\n') if len(val) > 0]

def validPassphrase(passphrase):
    words = set()
    for word in passphrase:
        l = len(words)
        words.add(word)
        if l == len(words):
            return False
    return True

def countValidPassphrases(passphrases):
    count = sum(
        [1 for passphrase in passphrases
            if validPassphrase(passphrase)
        ])
    return count

if __name__ == "__main__":
    print('hi')
    data = reader(filename)
    passphrases = parser(data)
    count = countValidPassphrases(passphrases)
    print(count)
