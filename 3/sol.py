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

    def preOrderOrig(self, root):
        A = []
        if root is not None:
            A.append(root.val)
            A.extend(self.preOrderOrig(root.left))
            A.extend(self.preOrderOrig(root.right))
        return A

    def preOrder(self, root):
        A = []
        if root is not None:
            A.append(root.val)
            if root.left is not None:
                A.extend(self.preOrder(root.left))
            else:
                A.append(None)
            if root.right is not None:
                A.extend(self.preOrder(root.right))
            else:
                A.append(None)
            return A
        else:
            return None


    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        A =  self.preOrder(root)
        if A is None:
            return None
        return ','.join(list(map(str, A)))

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data is None:
            return None
        def helper(lst):
            first = lst.pop(0)
            if first is None:
                return None
            else:
                root = TreeNode(first)
                root.left = helper(lst)
                root.right = helper(lst)
                return root

        A = data.split(',')
        A = [int(a) if a!='None' else None for a in A ]
        return helper(A)

if __name__ == '__main__':
    import random
    myTree = TreeNode()
    for _ in range(10):
        myTree.insertNode(random.randint(1, 100))
    Tree = TreeNode()
    print('Pre-Order Traversal of tree used =', Tree.preOrderOrig(myTree))
    out = Tree.serialize(myTree)
    print('Serialized tree = ', out)
    tre = Tree.deserialize(out)
    print('Pre-Order Traversal of deserialized tree =', Tree.preOrderOrig(tre))
    print('Serialized string for the deserialized tree =', Tree.serialize(tre))
