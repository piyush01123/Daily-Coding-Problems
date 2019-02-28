
from tree import Node
import random

class TreeNode(Node):
    def __init__(self, val=None):
        super().__init__(data=val)
        self._lock_state = False

    def insertNode(self, val):
        if self.left is None and self.right is not None:
            self.left = TreeNode(val)
            self.left.parent = self
        elif self.right is None and self.left is not None:
            self.right = TreeNode(val)
            self.right.parent = self
        elif self.left is None and self.right is None:
            choice = random.choice(['LEFT', 'RIGHT'])
            if choice=='LEFT':
                self.left = TreeNode(val)
                self.left.parent = self
            else:
                self.right = TreeNode(val)
                self.right.parent = self
        elif self.left is not None and self.right is not None:
            choice = random.choice(['LEFT', 'RIGHT'])
            if choice=='LEFT':
                self.left.insertNode(val)
            else:
                self.right.insertNode(val)

    def lock(self):
        if self.parent._lock_state or self.left._lock_state or self.right._lock_state:
            return False, 'Not possible'
        self._lock_state = True
        return True

    def unlock(self):
        if self.parent._lock_state or self.left._lock_state or self.right._lock_state:
            return False, 'Not possible'
        self._lock_state = False
        return True

    def is_locked(self):
        return self._lock_state

if __name__=='__main__':
    tree = TreeNode('*')
    for _ in range(20):
        val = random.randint(1, 100)
        tree.insertNode(val)
    tree.prettyPrint()
    print('\n\n\n')
    print(tree.left.lock()) #should lock and returnn true
    print(tree.is_locked()) #should be false
    print(tree.left.is_locked()) #should be true
    print(tree.left.left.is_locked()) #should be false
    print(tree.left.left.unlock()) #should not be possible
    print(tree.left.unlock()) #should be possible
    print(tree.left.left.is_locked()) #should be false
