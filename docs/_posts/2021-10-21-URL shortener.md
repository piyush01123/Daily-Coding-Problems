---
layout: post
title: "URL shortener"
categories: misc
---

This problem was asked by Microsoft.

Implement a URL shortener with the following methods:

`shorten(url)`, which shortens the url into a six-character alphanumeric string, such as `zLg6wl`.
`restore(short)`, which expands the shortened string into the original url. If no such shortened string exists, return `null`.
Hint: What if we enter the same URL twice?


My Solution(Python):
```

ALLOWED_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

class URLShortener:
    def __init__(self):
        self.url_store = {}
        self.urls_shortened = 1000000000 #assume 1000000000 URLs have been already registered

    def shorten(self, url):
        self.urls_shortened+=1
        self.url_store[self.urls_shortened] = url
        num_b62 = self.convertToBase(self.urls_shortened, 62)
        return ''.join(self.numToChar[i] for i in num_b62)

    def restore(self, short):
        num_b62 = [self.charToNum[char] for char in short]
        num = self.convertToDecimal(num_b62, 62)
        return self.url_store[num]

    @staticmethod
    def convertToBase(n: int, base: int) -> list:
        A = []
        while n:
            A.append(n%base)
            n//=base
        return A

    @staticmethod
    def convertToDecimal(num_base: list, base: int) -> int:
        num = 0
        for i, digit in enumerate(num_base):
            factor = base**i
            num+=factor*digit
        return num

    @property
    def charToNum(self):
        return {letter: i for i, letter in enumerate(ALLOWED_CHARS)}

    @property
    def numToChar(self):
        return {i: letter for i, letter in enumerate(ALLOWED_CHARS)}

if __name__=='__main__':
    shortener = URLShortener()
    short1 = shortener.shorten('https://medium.freecodecamp.org/the-art-of-computer-programming-by-donald-knuth-82e275c8764f')
    short2 = shortener.shorten('https://www.youtube.com/watch?v=Pt0nqbSJiEE')
    print(short1, shortener.restore(short1))
    print(short2, shortener.restore(short2))
```
