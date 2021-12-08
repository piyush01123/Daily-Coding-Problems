---
layout: post
title: "Word Matrix"
categories: misc
---

This problem was asked by Microsoft.

Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:
```
[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
```
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, given the target word 'MASS', you should return true, since it's the last row.


My Solution(Python):
```
class TrieNode:
    def __init__(self, ch='*'):
        self.links = []
        self.char = ch
        self.isWord = False
        self.countPrefix = 0

    def insert(self, root, word):
        for letter in word:
            foundPrefix = False
            for link in root.links:
                if link.char == letter:
                    foundPrefix = True
                    root.countPrefix += 1
                    root = link
                    break
                else:
                    pass
            if not foundPrefix:
                newnode = TrieNode(letter)
                root.links.append(newnode)
                root = newnode
        root.isWord = True

    def search(self, root, word):
        for i, letter in enumerate(word):
            foundPrefix = False
            for link in root.links:
                if link.char == letter:
                    # print(letter)
                    foundPrefix = True
                    return self.search(link, word[i+1::])
            if not foundPrefix:
                return False
        if root.isWord:
            return True
        else:
            # print('Found but not a word')
            return False


def findWord(M, target_word):
    T = TrieNode()
    for horiz in M:
        T.insert(T, ''.join(horiz))
    for i in range(len(M[0])):
        word = ''.join([m[i] for m in M])
        T.insert(T, word)
    return T.search(T, target_word)

M = [['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

print(findWord(M, 'FOAM'))
print(findWord(M, 'MASS'))
```
