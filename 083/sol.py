
from tree import Node
import random

class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)

    def insertNode(self, val):
        if self.data is None:
            self.data = val
        elif val<=self.data:
            if self.left is None:
                self.left = TreeNode(val)
            else:
                self.left.insertNode(val)
        else:
            if self.right is None:
                self.right = TreeNode(val)
            else:
                self.right.insertNode(val)

def reverseTree(root):
    if root is None:
        return None
    root.left, root.right = reverseTree(root.right), reverseTree(root.left)
    return root

def main():
    myTree = TreeNode()
    for _ in range(10):
        val = random.randint(1, 100)
        myTree.insertNode(val)
    myTree.prettyPrint()
    print('\n\n\n')
    rev_tree = reverseTree(myTree)
    rev_tree.prettyPrint()
    print('\n')

if __name__=='__main__':
    main()
