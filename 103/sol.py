
INT_LARGE = 10**5

def shortestSubstring(s, chars):
    left = 0
    right = 0
    l_min = INT_LARGE
    while right < len(s):
        while right < len(s) and not all(char in s[left:right] for char in chars):
            right+=1
        while all(char in s[left:right] for char in chars):
            left+=1
        # print(s[left-1:right])
        if right-left+1 < l_min:
            sub = s[left-1:right]
            l_min = right-left+1
    return sub

if __name__=='__main__':
    print(shortestSubstring(s="figehaeci", chars={'a', 'e', 'i'}))
    print(shortestSubstring(s="figehaieci", chars={'a', 'e', 'i'}))
