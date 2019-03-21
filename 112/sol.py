
from tree import Node


class TreeNode(Node):
    """
    Binary Tree data structure with inheritance from a vis lib with custom
    methods
    """
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def findPath(root, node, path):
    """
    Modifies path argument to store path from root to node
    """
    if root is None:
        return False
    path.append(root)
    if root==node:
        return True
    if (root.left is not None and findPath(root.left, node, path)) or   (root.right is not None and findPath(root.right, node, path)):
        return True
    path.pop()
    return False


def findLCA(root: TreeNode, v: TreeNode, w: TreeNode) -> TreeNode:
    """
    Finds LCA of nodes v and w for a tree with root 'root'
    """
    path_v = []
    path_w = []
    findPath(root, v, path_v)
    findPath(root, w, path_w)
    i = 0
    while i<min(len(path_v), len(path_w)):
        if path_v[i] != path_w[i]:
            break
        i+=1
    return path_v[i-1]


def main():
    """
    Builds a test case and runs test for LCA
    """
    root = TreeNode(1)
    l = root.left = TreeNode(2)
    r = root.right = TreeNode(3)
    ll = root.left.left = TreeNode(4)
    lr = root.left.right = TreeNode(5)
    rl = root.right.left = TreeNode(6)
    rr = root.right.right = TreeNode(7)
    root.prettyPrint(); print('\n')
    for v, w in [(ll, lr), (ll, rl), (r, ll), (l, ll)]:
        lca = findLCA(root, v, w)
        print('v=%s, w=%s, lca=%s' %(v.data, w.data, lca.data))


if __name__=='__main__':
    main()
