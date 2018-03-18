word = "3113322113"
result = ""
count =0;
for i in range(40):

    if len(word) == 1:
        result += "1" + word
    else:
        for j in range(len(word)-1):
            curr = word[j]
            count+=1
            if (curr != word[j+1]):
                result += str(count)+curr
                count=0
        if (curr == word[len(word)-1]):
            result += str(count+1)+curr
        else:
            result += "1" + word[len(word)-1]

    word = result
    result = ""


print len(word)
