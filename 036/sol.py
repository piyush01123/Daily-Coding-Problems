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
                self.right.insertNode(val)

    def preOrderTraversal(self):
        A = []
        if self is not None:
            A.append(self.val)
            if self.left is not None:
                A.extend(self.left.preOrderTraversal())
            if self.right is not None:
                A.extend(self.right.preOrderTraversal())
        return A

    def secondHighestElement(self):
        A = self.preOrderTraversal()
        if len(A)<=2:
            return min(A)
        h1, h2 = A[0], A[1]
        for i in range(2, len(A)):
            if A[i]>h1 and A[i]>h2:
                h1, h2 = A[i], h1
            elif A[i]>h2:
                h2 = A[i]
            else:
                pass
        return h2

if __name__=='__main__':
    import random
    myTree = TreeNode()
    for _ in range(10):
        val = random.randint(1, 100)
        myTree.insertNode(val)
    print('Keys =', myTree.preOrderTraversal(), '2nd Highest Element =', myTree.secondHighestElement())
