from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build(nodes: List) -> TreeNode:
    assert len(nodes) > 0
    root = TreeNode(nodes[0])
    queue = [root]
    index = 1
    
    while index < len(nodes):
        current = queue.pop(0)

        if nodes[index] is not None:
            current.left = TreeNode(nodes[index])
            queue.append(current.left)
        index += 1

        if index >= len(nodes):
            break
        
        if nodes[index] is not None:
            current.right = TreeNode(nodes[index])
            queue.append(current.right)
        index += 1
    
    return root

class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        def fix(node: TreeNode):
            new_left = node.left
            while new_left:
                if new_left.val < low:
                    new_left = new_left.right
                else:
                    break
            node.left = new_left

            if node.left:
                fix(node.left)

            new_right = node.right
            while new_right:
                if new_right.val > high:
                    new_right = new_right.left
                else:
                    break
            node.right = new_right

            if node.right:
                fix(node.right)

        while root:
            if root.val < low:
                root = root.right
            elif root.val > high:
                root = root.left
            else:
                break
        
        if root:
            fix(root)
        
        return root
    
def toList(node: TreeNode) -> List:
    result = []
    queue = [node]
    while True:
        current = queue.pop(0)
        result.append(current.val)
        
        if current.val is not None and (current.left or current.right):
            if current.left:
                queue.append(current.left)
            else:
                queue.append(TreeNode(None))

            if current.right:
                queue.append(current.right)
            else:
                queue.append(TreeNode(None))
        
        if len(queue) == 0:
            break
    return result

if __name__ == "__main__":
    nodes = [1,0,2]
    low = 1
    high = 2

    root = build(nodes)
    # print(toList(root))
    
    s = Solution()
    root = s.trimBST(root, low, high)
    print(toList(root))