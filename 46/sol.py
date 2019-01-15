def longestPalindrome(S: str) -> str:
    # brute force solution
    n = len(S)
    max_length = 0
    for i in range(n):
        for j in range(i+1, n+1):
            substring = S[i:j]
            lsub = len(substring)
            if substring[:lsub//2]==substring[:lsub//2:-1]:
                if lsub >= max_length:
                    longest_palindrome = substring
                    max_length = lsub
    return longest_palindrome

print(longestPalindrome("aabcdcb"))
print(longestPalindrome("bananas"))
print(longestPalindrome("pad"))

def longestPalindrome(S: str) -> str:
    # DP solution
    n = len(S)
    max_length = 1
    is_palindrome = [[None for _ in range(n)] for _ in range(n)]

    for i in range(n):
        is_palindrome[i][i] = True

    longest_palindrome = S[0] #in case we dont get anything later

    for i in range(n-1):
        if S[i] == S[i+1]:
            is_palindrome[i][i+1] = True
            longest_palindrome = S[i:i+2]
            max_length = 2
        else:
            is_palindrome[i][i+1] = False

    for k in range(3, n+1): #k is the length of substring
        for i in range(n-k+1):
            j = i+k
            # print('at k=',k, S[i:j], i, j)
            if is_palindrome[i+1][j-2] and S[i]==S[j-1]:
                # print('Current palindrome', S[i:j])
                if k>max_length:
                    max_length = k
                    longest_palindrome = S[i:j]
                is_palindrome[i][j-1] = True
            else:
                is_palindrome[i][j-1] = False
    # for row in is_palindrome:
    #     print(row)
    return longest_palindrome


print(longestPalindrome("aabcdcb"))
print(longestPalindrome("bananas"))
print(longestPalindrome("pad"))
