import d4p1

def sortStr(word):
    return ''.join(sorted(word))

def validPassphrase(passphrase):
    words = set()

    for word in passphrase:

        word = sortStr(word)
        l = len(words)
        words.add(word)
        if l == len(words):
            return False
    return True

d4p1.validPassphrase = validPassphrase

if __name__ == "__main__":
    print('hi')
    data = d4p1.reader(d4p1.filename)
    passphrases = d4p1.parser(data)
    count = d4p1.countValidPassphrases(passphrases)
    print(count)
