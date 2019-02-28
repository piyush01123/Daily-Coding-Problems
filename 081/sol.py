
import itertools

def possibleLetters(mapping, digit_string):
    letters = []
    for digit in digit_string:
        letters.append(mapping[digit])
    combs = [''.join(p) for p in itertools.product(*letters)]
    return combs

def main():
    print(possibleLetters({'2': ['a', 'b', 'c'], '3': ['d', 'e', 'f']}, '23'))

if __name__=='__main__':
    main()
