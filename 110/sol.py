
from tree import Node

class TreeNode(Node):
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def allPaths(root):
    if root is None:
        return []
    A = []
    if root.left is  None and root.right is None:
        A.append([root.data])
    else:
        lp = allPaths(root.left)
        rp = allPaths(root.right)
        for path in lp+rp:
            A.append([root.data+p] for p in path)
    return A


if __name__=='__main__':
    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(5)
    tree.prettyPrint(); print('\n')
    print(allPaths(tree))
