
/*
Huffman Encoding: Given a frequency map of signs, create a new compressed representation.
Algorithm: 
1. Create a data structure for node with prob, sign, left, right pointers
2. Create a min heap of nodes with prob as key. For each item in frequency map; insert node(p, s, NULL, NULL) into the min heap.
3. while the min heap has more than 1 element: Do
 a) pop two nodes
 b) create a parent node with these two nodes as its children
 c) push parent node into the min heap
4. The last remaining node in the min heap is the root of the Huffman Tree.
5. Traverse through the tree and keep adding 0 for left and 1 for right to a prefix started with empty string.
6. Our signs reside only at the leaf nodes. Huffman Code for a sign is the accumulated prefix at the corresponding leaf node.
Complexity: nlog(n)
Entropy H = -Sum over signs [p(sign)*log_2(p(sign))]
Average code length = H
*/


#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

struct node{
  double data;
  char sign;
  node *left, *right;
};

node *createNode(double p, char s, node *l, node *r){
  node *temp = new node;
  temp->data = p;
  temp->sign = s;
  temp->left = l;
  temp->right = r;
  return temp;
}

struct comp{
  bool operator()(node *n1, node *n2){
    return n1->data > n2->data;
  }
};

void encode(node *root, std::string prefix, std::unordered_map<char, std::string> &codes){
  if (root==NULL) return;
  if (root->left==NULL && root->right==NULL){
    codes[root->sign] = prefix;
  }
  encode(root->left, prefix+"0", codes);
  encode(root->right, prefix+"1", codes);
}

std::unordered_map<char, std::string> huffman(std::unordered_map<char, double> freq_map){
    std::priority_queue<node*, std::vector<node*>, comp> pq;
    for (auto item: freq_map){
      node *n = createNode(item.second, item.first, NULL, NULL);
      pq.push(n);
    }
    while(pq.size()>1){ // last node in pq will simply have P=1 so no use of that
      node *left = pq.top(); pq.pop();
      node *right = pq.top(); pq.pop();
      node *parent = createNode(left->data+right->data, '\0', left, right);
      pq.push(parent);
    }
    node *root = pq.top();
    std::unordered_map<char, std::string> codes;
    encode(root, "", codes);
    return codes;
}

int main(){
  std::unordered_map<char, double> freq_map {{'A', 0.1}, {'B', 0.4}, {'C', 0.06}, {'D', 0.1}, {'E', 0.04}, {'F', 0.3}};
  std::unordered_map<char, std::string> huffman_codes = huffman(freq_map);
  for (auto item: huffman_codes){
    std::cout << item.first << ' ' << item.second << '\n';
  }
  return 0;
}
