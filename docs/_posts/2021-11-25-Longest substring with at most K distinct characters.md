---
layout: post
title: "Longest substring with at most K distinct characters"
categories: misc
---

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = `"abcba"` and k = 2, the longest substring with k distinct characters is `"bcb"`.


My Solution(Python):
```

def longestSubstring(s, k):
    #Base case
    if len(s)<=k:
        return s
    start = 0
    end = 0
    l = 0 #length of longest substring
    counter = 0 #counts number of unique characters
    sub = ""
    H = {l: 0 for l in 'abcdefghijklmnopqrstuvwxyz'} #frequency map
    while end < len(s):
        if H[s[end]] == 0:
            counter += 1
        while counter > k:
            if H[s[start]] == 1:
                counter -= 1
            H[s[start]] -= 1
            start += 1
        H[s[end]] += 1
        end += 1
        if end-start > l:
            sub = s[start: end]
            l = end-start
    return sub



if __name__=='__main__':
    print(longestSubstring(s="abcba", k=2))
    print(longestSubstring(s="abccba", k=2))
```
