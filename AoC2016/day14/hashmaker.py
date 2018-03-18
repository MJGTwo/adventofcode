import hashlib

def md5(string):
    m= hashlib.md5(string).hexdigest()
    #print m
    return m




def stretchhash(hash):
    i = 0
    while i <= 2016:
        hash = md5(hash)
        i+=1
    #print hash
    return hash

if __name__ == "__main__":
    f = open("hashes.txt","w")
    for i in range(100000):
        f.write("ihaygndm"+str(i)+"\t"+stretchhash("ihaygndm"+str(i))+"\n")
    f.close()
