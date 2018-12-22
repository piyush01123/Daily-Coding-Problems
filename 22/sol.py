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
