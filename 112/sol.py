
from tree import Node

class TreeNode(Node):
    def __init__(self, data):
        super(TreeNode, self).__init__(data=data)


def findPath(root, node, path):
    if root is None:
        return False
    if root==node:
        return True
    path.append(node)
    if (root.left is not None and findPath(root.left, node, path)) or \
       (root.right is not None and findPath(root.right, node, path)):
       return True
    path.pop()
    return False


def findLCA(root: TreeNode, v: TreeNode, w: TreeNode) -> TreeNode:
    path_v = []
    path_w = []
    findPath(root, v, path_v)
    findPath(root, w, path_w)
    for n in path_v:
        print(n, n.data)
    # print(path_v, path_w)
    # i = 0
    # while i<min(len(path_v), len(path_w)):
    #     if path_v[i] != path_w[i]:
    #         break
    #     return path_v[i-1]

def main():
    root = TreeNode(1)
    l = root.left = TreeNode(2)
    r = root.right = TreeNode(3)
    ll = root.left.left = TreeNode(4)
    lr = root.left.right = TreeNode(5)
    rl = root.right.left = TreeNode(6)
    rr = root.right.right = TreeNode(7)
    root.prettyPrint(); print('\n')
    # for v, w in [(ll, lr), (ll, rl), (r, ll), (l, ll)]:
    for v, w in [(ll, lr)]:
        lca = findLCA(root, v, w)
        # print(lca, lca.data)


if __name__=='__main__':
    main()
