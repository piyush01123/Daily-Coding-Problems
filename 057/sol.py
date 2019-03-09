
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
