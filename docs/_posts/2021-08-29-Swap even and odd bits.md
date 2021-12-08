---
layout: post
title: "Swap even and odd bits"
categories: misc
---

This problem was asked by Cisco.

Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.

For example, 10101010 should be 01010101. 11100010 should be 11010001.

Bonus: Can you do this in one line?


My Solution(Python):
```

def swapBits(num: int) -> int:
    e_bits = num & 0b10101010
    o_bits = num & 0b01010101
    return bin(e_bits>>1 | o_bits<<1)


if __name__=='__main__':
    print(swapBits(0b10101010))
    print(swapBits(0b11100010))
```
