
def shortestSubstring(s, chars):
    if not s or not chars:
        return None
    left = 0
    right = 0
    found = False
    while right < len(s):
        while right < len(s) and not all(char in s[left:right] for char in chars):
            right+=1
        while all(char in s[left:right] for char in chars):
            found = True
            left+=1
            sub = s[left-1:right]
    if not found:
        return "characters from set not present in string"
    return sub

if __name__=='__main__':
    print(shortestSubstring(s="figehaeci", chars={'a', 'e', 'i'}))
    print(shortestSubstring(s="figehaieci", chars={'a', 'e', 'i'}))
    print(shortestSubstring(s="figehaieci", chars={'a', 'z'}))
    print(shortestSubstring(s="", chars={'a', 'z'}))
    print(shortestSubstring(s="figehaieci", chars=set()))
