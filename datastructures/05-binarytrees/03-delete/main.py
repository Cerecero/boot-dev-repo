class BSTNode:
    def delete(self, val):
        if self.val is None:
            return None

        if val < self.val:
            if self.left:
                temp = self.left.delete(val)
                self.left = temp
            return self
        elif val > self.right:
            if self.right:
                temp = self.right.delete(val)
                self.right = temp
            return self

        else:
            if self.right is None:
                return self.left
            elif self.left is None:
                return self.right

        min_larger_node = self.right.find_min()
        self.val = min_larger_node.val
        self.right = self.right.delete(min_larger_node.val)
        return self

    def find_min(self):
        # Helper method to find the minimum value in a subtree
        current = self
        while current.left:
            current = current.left
        return current


    # don't touch below this line

    def __init__(self, val=None):
        self.left = None
        self.right = None
        self.val = val

    def insert(self, val):
        if not self.val:
            self.val = val
            return

        if self.val == val:
            return

        if val < self.val:
            if self.left:
                self.left.insert(val)
                return
            self.left = BSTNode(val)
            return

        if self.right:
            self.right.insert(val)
            return
        self.right = BSTNode(val)
