---
layout: post
title: "String Break"
categories: misc
---

This problem was asked by Amazon.

Given a string s and an integer k, break up the string into multiple texts such that each text has a length of k or less. You must break it up so that words don't break across lines. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that there is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"]. No string in the list has a length of more than 10.


My Solution(Python):
```

def stringBreak(string: str, k: int) -> 'list(str)':
    str_brk = []
    words = string.split()
    for i, word in enumerate(words):
        if i==0 or len(str_brk[-1]) + len(word) + 1 > k:
            str_brk.append(word)
        else:
            str_brk[-1] += " " + word
    return str_brk


if __name__=='__main__':
    print(stringBreak(string="the quick brown fox jumps over the lazy dog", k=10))
```
