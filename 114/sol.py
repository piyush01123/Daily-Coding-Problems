
def reverseWords(s: str, delim: list) -> str:
    words = []
    delimiters = []
    i = 0
    while i<len(s):
        j = i
        while j<len(s) and s[j] not in delim:
            j += 1
        words.append(s[i: j])
        delimiter = ""
        while j<len(s) and s[j] in delim:
            delimiter += s[j]
            j+=1
        delimiters.append(delimiter)
        i = j
    # print(words, delimiters)
    return ''.join(a+b for a, b in zip(words[::-1], delimiters))


if __name__=='__main__':
    print(reverseWords(s="hello/world:here", delim=[':', '/']))
    print(reverseWords(s="hello/world:here/", delim=[':', '/']))
    print(reverseWords(s="hello//world:here", delim=[':', '/']))
