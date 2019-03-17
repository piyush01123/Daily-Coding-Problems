
from tree import Node


class TreeNode(Node):
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def findDepth(root):
    if root is None:
        return 0
    else:
        return 1 + max(findDepth(root.left), findDepth(root.right))


def printLevel(root, d, x):
    if x==d and root is not None:
        print(root.data)
    if x>d:
        return
    if root.left is not None:
        printLevel(root.left, d, x+1)
    if root.right is not None:
        printLevel(root.right, d, x+1)


def printTreeLevelWise(root):
    depth = findDepth(root)
    for d in range(depth):
        printLevel(root, d, x=0)


def  main():
    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(5)
    tree.prettyPrint(); print('\n')
    printTreeLevelWise(tree)

    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.left.left = TreeNode(4)
    tree.left.right = TreeNode(5)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(5)
    tree.right.left.left = TreeNode(6)
    tree.right.left.right = TreeNode(7)
    tree.right.right.left = TreeNode(8)
    tree.right.right.right = TreeNode(9)
    tree.prettyPrint(); print('\n')
    printTreeLevelWise(tree)


if __name__=='__main__':
    main()
