
class Node:
    def __init__(self, val=None):
        self.val = val
        self.left = None
        self.right = None

    def inOrderTraversal(self):
        A = []
        if self is not None:
            if self.left is not None:
                A.extend(self.left.inOrderTraversal())
            A.append(self.val)
            if self.right is not None:
                A.extend(self.right.inOrderTraversal())
        return A

    def modInOrderTraversal(self):
        A = []
        if self is not None:
            if self.left is not None:
                A.append('(')
                A.extend(self.left.modInOrderTraversal())
                A.append(')')
            A.append(self.val)
            if self.right is not None:
                A.append('(')
                A.extend(self.right.modInOrderTraversal())
                A.append(')')
        return A

    def evaluate(self):
        A = self.modInOrderTraversal()
        A = list(map(str, A))
        expression = ''.join(A)
        return eval(expression)

if __name__=='__main__':
    tree = Node('*')
    tree.left = Node('+')
    tree.right = Node('+')
    tree.left.left = Node(3)
    tree.left.right = Node(2)
    tree.right.left = Node(4)
    tree.right.right = Node(5)
    value = tree.evaluate()
    print(value)
