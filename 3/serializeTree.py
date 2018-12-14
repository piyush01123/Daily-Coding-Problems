# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x=None):
        self.val = x
        self.left = None
        self.right = None
    def insertNode(self, val):
        if not self.val:
            self.val = val
        elif val <= self.val:
            if not self.left:
                self.left = TreeNode(val)
            else:
                self.left.insertNode(val)
        else:
            if not self.right:
                self.right = TreeNode(val)
            else:
                self.right.insertNode(val)


def serialize(root):
    """Encodes a tree to a single string.

    :type root: TreeNode
    :rtype: str
    """
    out = ""
    if root is None:
        out = out + "-1==>"
        return out
    out = out + str(root.val) + "==>"
    out = out + serialize(root.left)
    out = out + serialize(root.right)
    return out


def deserialize(data):
    """Decodes your encoded data to tree.

    :type data: str
    :rtype: TreeNode
    """
    # print('Running with data'+data+'data')
    if data == "" or data == " " or data == "==>" or int(data.split('==>')[0])==-1:
        data = "==>".join(data.split("==>")[1:])
        return None
    val = int(data.split('==>')[0])
    # print('Found val %d' %val)
    root = TreeNode(val)
    if data:
        data = "==>".join(data.split("==>")[1:])
        root.left = deserialize(data)
        root.right = deserialize(data)
    return root


if __name__ == '__main__':
    import random
    myTree = TreeNode()
    for _ in range(10):
        myTree.insertNode(random.randint(1, 100))
    out = serialize(myTree)
    print('xxx'+out+'xxx')
    tre = deserialize(out)
    print('yyy'+serialize(tre)+'yyy')
