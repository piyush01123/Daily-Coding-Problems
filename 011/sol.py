"""Leetcode version"""
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.prefixes = set()
        self.words = set()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        for i in range(1, len(word)+1):
            self.prefixes.add(word[:i])
        self.words.add(word)


    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        return word in self.words


    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        return prefix in self.prefixes


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

"""Proper TRIE (I like this one more)"""
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
                    print(letter)
                    foundPrefix = True
                    return self.search(link, word[i+1::])
            if not foundPrefix:
                return False
        if root.isWord:
            return True
        else:
            print('Found but not a word')
            return False

    def startsWith(self, root, prefix):
        for i, letter in enumerate(prefix):
            foundPrefix = False
            for link in root.links:
                if link.char == letter:
                    print(letter)
                    foundPrefix = True
                    return self.startsWith(link, prefix[i+1:])
            if not foundPrefix:
                return False
        return True

if __name__=='__main__':
    root = TrieNode()
    root.insert(root, 'hackathon')
    print(root.search(root, 'hackathon'))
    root.insert(root, 'apple')
    print(root.search(root, 'apple'))
    print(root.search(root, 'app'))
    print(root.startsWith(root, 'app'))
    root.insert(root, 'app')
    print(root.search(root, 'app'))
