class TreeNode(object):
    def __init__(self, x=None):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
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


    def preOrderTraversal(self, root):
        A = []
        if root is not None:
            A.append(root.val)
            A.extend(self.preOrderOrig(root.left))
            A.extend(self.preOrderOrig(root.right))
        return A

    def univalTree(self, root):
        # The Daily Coding Probelems version ie all nodes under it have the same value.
        count = 0
        if root is not None:
            if root.left is None or root.right is None or root.left.val==root.right.val:
                count+=1
            count+=self.univalTree(root.left)
            count+=self.univalTree(root.right)
        return count

    def univalTree_v2(self, root):
        # The GeeksforGeeks version ie all the nodes have same value
        count = 0
        if root is not None:
            if root.left is None or root.right is None or (root.left.val==root.right.val==root.val):
                count+=1
            count+=self.univalTree_v2(root.left)
            count+=self.univalTree_v2(root.right)
        return count

def main():
    sol = Solution()
    tree_string = '7,1,7,None,None,7,None,None,7,None,7,None,None'
    tree = sol.deserialize(tree_string)
    print('Actual = %s\nRecreated = %s'%(tree_string, sol.serialize(tree)))
    print(sol.univalTree(tree))
    print(sol.univalTree_v2(tree))

    tree_string = '5,4,4,None,None,4,None,None,5,None,5,None,None'
    tree = sol.deserialize(tree_string)
    print('Actual = %s\nRecreated = %s'%(tree_string, sol.serialize(tree)))
    print(sol.univalTree(tree))
    print(sol.univalTree_v2(tree))

    tree_string = '0,1,None,None,0,1,1,None,None,1,None,None,0,None,None'
    tree = sol.deserialize(tree_string)
    print('Actual = %s\nRecreated = %s'%(tree_string, sol.serialize(tree)))
    print(sol.univalTree(tree))
    print(sol.univalTree_v2(tree))

if __name__=='__main__':
    main()
