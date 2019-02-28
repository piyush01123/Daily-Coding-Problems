
"""
Fisher-Yates Algorithm
https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
"""
import numpy as np

def randK(k: int) -> int:
    return np.random.randint(0, k+1)

def shuffleDeck(cards: list, k: int) -> list:
    n = len(cards)
    for i in range(n-1, 0, -1):
        j = randK(i)
        cards[i], cards[j] = cards[j], cards[i]
    return cards

print(shuffleDeck(cards=list(range(1, 53)), k=10))
