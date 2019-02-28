
from tree import Node
import random

class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)

def isValidBST(root):
    if root is None:
        return True
    if root.left is not None:
        c1 = root.left.data<=root.data
    else:
        c1 = True
    if root.right is not None:
        c2 = root.right.data>=root.data
    else:
        c2 = True
    return c1 and c2 and isValidBST(root.left) and isValidBST(root.right)


def main():
    tree = TreeNode(11); tree.left=TreeNode(10); tree.left.right=TreeNode(10.5); tree.right=TreeNode(12); tree.right.left=TreeNode(11.5)
    tree.prettyPrint()
    print('\n\n', isValidBST(tree))

if __name__=='__main__':
    main()
