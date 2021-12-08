---
layout: post
title: "Autocomplete system"
categories: misc
---

This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.


My Solution(C++):
```

#include <iostream>
#include <vector>
#include <string>
#define NUM_ALPHABETS 26

struct trie{
  trie *children[NUM_ALPHABETS];
  bool isWordEnd;
};

trie *createTrieNode(){
  trie *temp = new trie;
  for (int i=0; i<NUM_ALPHABETS; i++){
    temp->children[i] = nullptr;
  }
  temp->isWordEnd = false;
  return temp;
}

bool isLastNode(trie *root){
  for (int i=0; i<NUM_ALPHABETS; i++){
    if (root->children[i]!=nullptr){
      return false;
    }
  }
  return true;
}

void getAllWords(trie *root, std::string currPrefix, std::vector<std::string> &words){
  // std::cout<<"called with prefix "<<currPrefix<<'\n';
  if (root->isWordEnd){
    words.push_back(currPrefix);
    // std::cout<<"added word "<<currPrefix<<'\n';
  }
  if (isLastNode(root)){
    return;
  }
  for (int i=0; i<NUM_ALPHABETS; i++){
    if (root->children[i]!=nullptr){
      char c = 'a'+i;
      // currPrefix.push_back(c);
      getAllWords(root->children[i], currPrefix+c, words);
    }
  }
}


class prefixTree{
private:
  int num_words;
  trie *root;
public:
  prefixTree();
  void insert(std::string key);
  bool search(std::string key);
  bool searchPrefix(std::string key);
  int getNumWords();
  std::vector<std::string> wordsWIthPrefix(std::string key);
};

prefixTree::prefixTree(){
  root = createTrieNode();
  num_words = 0;
}

void prefixTree::insert(std::string key){
  trie *crawler = this->root;
  for (char c: key){
    int idx = c-'a';
    if (crawler->children[idx]==nullptr){
      crawler->children[idx] = createTrieNode();
    }
    crawler = crawler->children[idx];
  }
  crawler->isWordEnd = true;
  this->num_words++;
}

bool prefixTree::search(std::string key){
  trie *crawler = this->root;
  for (char c: key){
    int idx = c-'a';
    if (crawler->children[idx]==nullptr){
      return false;
    }
    crawler = crawler->children[idx];
  }
  return crawler!=nullptr && crawler->isWordEnd;
}

bool prefixTree::searchPrefix(std::string key){
  trie *crawler = this->root;
  for (char c: key){
    int idx = c-'a';
    if (crawler->children[idx]==nullptr){
      return false;
    }
    crawler = crawler->children[idx];
  }
  return crawler!=nullptr;
}

int prefixTree::getNumWords(){
  return this->num_words;
}

std::vector<std::string> prefixTree::wordsWIthPrefix(std::string key){
  if (!this->searchPrefix(key)){
    return {};
  }
  if (this->search(key)){
    return {key};
  }
  std::vector<std::string> words;
  trie *crawler = this->root;
  for (char c: key){
    int idx = c-'a';
    if (crawler->children[idx]==nullptr){
      return {};
    }
    crawler = crawler->children[idx];
  }
  getAllWords(crawler, key, words);
  return words;
}

void test(){
  prefixTree pt;
  pt.insert("thus");
  pt.insert("this");
  pt.insert("there");
  pt.insert("thin");
  // pt.search("thin")?std::cout<<"thin is present"<<'\n':std::cout<<"thin is not present"<<'\n';
  // pt.search("then")?std::cout<<"then is present"<<'\n':std::cout<<"then is not present"<<'\n';
  // std::cout<<"Number of words = "<<pt.getNumWords()<<'\n';
  std::vector<std::string> words = pt.wordsWIthPrefix("thi");
  for (std::string word: words){
    std::cout<<word<<'\n';
  }

}

int main(){
  test();
  return 0;
}
```


My Solution(Python):
```
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
```
