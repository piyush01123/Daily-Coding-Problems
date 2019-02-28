
from tree import Node
import random

class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)

    def insertNode(self, val):
        if self.data is None:
            self.data = val
        elif val<=self.data:
            if self.left is None:
                self.left = TreeNode(val)
            else:
                self.left.insertNode(val)
        else:
            if self.right is None:
                self.right = TreeNode(val)
            else:
                self.right.insertNode(val)


def findDepth(root: 'TreeNode') -> int:
    if root is None:
        return 0
    else:
        return 1 + max(findDepth(root.left), findDepth(root.right))

def deepestNode(root: 'TreeNode', depth: int) -> 'RootNode':
    if depth==1:
        return root
    else:
        depth_left = findDepth(root.left)
        depth_right = findDepth(root.right)
        if depth_left >= depth_right:
            return deepestNode(root.left, depth-1)
        else:
            return deepestNode(root.right, depth-1)

def main():
    myTree = TreeNode()
    for _ in range(5):
        val = random.randint(1, 100)
        myTree.insertNode(val)
    myTree.prettyPrint()
    print('\n')
    depth = findDepth(myTree)
    print('depth=', depth)
    deepest_node = deepestNode(myTree, depth)
    print('Deepest Node = %s' %deepest_node.data)

if __name__=='__main__':
    main()
