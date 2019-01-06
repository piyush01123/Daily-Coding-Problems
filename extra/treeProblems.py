class TreeNode:
    def __init__(self, val = None):
        self.val = val
        self.left = None
        self.right = None

    def insertNode(self, val):
        if self.val is None:
            self.val = val
        elif val<=self.val:
            if self.left is None:
                self.left = TreeNode(val)
            else:
                self.left.insertNode(val)
        else:
            if self.right is None:
                self.right = TreeNode(val)
            else:
                self.right.insert(val)

    def preOrderTraversal(self):
        A = []
        if self is not None:
            A.append(self.val)
            A.extend(self.left.preOrderTraversal())
            A.extend(self.right.preOrderTraversal())
        return A

    def countNodes(self):
        if self is None:
            return 0
        else:
            return self.left.countNodes() + self.right.countNodes() + 1

    def deepestNode(self):
        if self is not None and self.left is None and self.right is None:
            return self
        if self.left is None:
            return self.right.deepestNode()
        elif self.right is None:
            return self.left.deepestNode()

    def deepestNodeWithDepth(self):
        if self is not None and self.left is None and self.right is None:
            return self, 1
        if self.left is None:
            return self.increment_depth(self.right.deepestNodeWithDepth())
        if self.right is None:
            return self.increment_depth(self.left.deepestNodeWithDepth())
        return self.increment_depth(max(
        self.left.deepestNodeWithDepth(),
        self.right.deepestNodeWithDepth(),
        key=lambda x: x[1]))

    @staticmethod
    def increment_depth(node_depth_tuple):
        node, depth = node_depth_tuple
        return node, depth + 1
