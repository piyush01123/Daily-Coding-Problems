
#using split
def reverseWords(s: str) -> str:
    return ' '.join(s.split(' ')[::-1])


#without using split
def reverseWordsV2(s: str) -> str:
    # we can use block1 or block2 to find words
    # BLOCK1
    # words = []
    # curr = ''
    # for l in s:
    #     if l==' ':
    #         words.append(curr)
    #         curr = ''
    #     else:
    #         curr = curr+l
    # words.append(curr)

    #BLOCK2
    words = []
    i = 0
    while i<len(s):
        j = i
        while j<len(s) and s[j] != ' ':
            j+=1
        words.append(s[i:j])
        i = j+1

    t = ''
    for word in words[::-1]:
        t = t + word + " "
    return t


if __name__=='__main__':
    print(reverseWords("hello world here"))
    print(reverseWordsV2("hello world here"))
