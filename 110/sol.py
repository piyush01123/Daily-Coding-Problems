
from tree import Node

class TreeNode(Node):
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def allPaths(root, paths, path):
    if root is None:
        return False
    path.append(root.data)
    if root.left is None and root.right is None:
        paths.append(path)
        return True
    pathc1 = path.copy()
    pathc2 = path.copy()
    if root.left is not None:
        allPaths(root.left, paths, pathc1)
    if root.right is not None:
        allPaths(root.right, paths, pathc2)



if __name__=='__main__':
    tree = TreeNode(1)
    tree.left = TreeNode(2)
    tree.right = TreeNode(3)
    tree.right.left = TreeNode(4)
    tree.right.right = TreeNode(5)
    tree.prettyPrint(); print('\n')
    paths = []
    path = []
    allPaths(tree, paths, path)
    print(paths)
