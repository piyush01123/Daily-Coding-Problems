---
layout: post
title: "Run length encoding"
categories: misc
---

This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string `"AAAABBBCCDAA"` would be encoded as `"4A3B2C1D2A"`.

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.


My Solution(Python):
```

class RunLengthEncoding:
    @staticmethod
    def encode(string):
        string = list(string)
        char = string.pop(0)
        times = 1
        encoding = ""
        while string:
            this_char = string.pop(0)
            if this_char==char:
                times += 1
            else:
                encoding += "{0}{1}".format(times, char)
                times = 1
            char = this_char
        encoding += "{0}{1}".format(times, char)
        return encoding

    @staticmethod
    def decode(string):
        string = list(string)
        decoding = ""
        while string:
            times = int(string.pop(0))
            char = string.pop(0)
            decoding += times*char
        return decoding


if __name__=='__main__':
    rle = RunLengthEncoding()
    string = "AAAABBBCCDAA"
    encoded = rle.encode(string)
    decoded = rle.decode(encoded)
    print('-->'.join((string, encoded, decoded)))
```
