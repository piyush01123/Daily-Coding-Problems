
def swapBits(num: int) -> int:
    e_bits = num & 0b10101010
    o_bits = num & 0b01010101
    return bin(e_bits>>1 | o_bits<<1)


if __name__=='__main__':
    print(swapBits(0b10101010))
    print(swapBits(0b11100010))
