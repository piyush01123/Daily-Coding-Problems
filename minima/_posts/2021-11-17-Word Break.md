---
layout: post
title: "Word Break"
categories: misc
---

This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].


My Solution(Python):
```
def wordBreak(s, wordDict):
    """
    :type s: str
    :type wordDict: List[str]
    :rtype: str
    """
    L = len(s)
    ok = [True]
    breaks = [0]
    words = []
    for i in range(1, L+1):
        is_word = any(ok[j] and s[j:i] in wordDict for j in range(i))
        ok.append(is_word)
        if is_word:
            words.append(s[breaks[-1]:i])
            breaks.append(i)
    if not ok[-1]:
        return None
    return words

if __name__=='__main__':
    print(wordBreak("thequickbrownfox", ['quick', 'brown', 'the', 'fox']))
    print(wordBreak("bedbathandbeyond", ['bed', 'bath', 'bedbath', 'and', 'beyond']))
    print(wordBreak("thequickbrownfox", ['quick', 'brown', 'the', 'fox']))
    print(wordBreak("applepenapple", ['apple', 'pen']))
    print(wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"]))
```
