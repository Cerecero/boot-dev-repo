class BSTNode:
    def search_range(self, lower_bound, upper_bound):
        range_nodes = []
        if self.val is None:
            return range_nodes
        if self.val > lower_bound and self.left:
            range_nodes.extend(self.left.search_range(lower_bound, upper_bound))

        if lower_bound <= self.val <= upper_bound:
            range_nodes.append(self.val)

        if self.val < upper_bound and self.right:
            range_nodes.extend(self.right.search_range(lower_bound, upper_bound))

        return range_nodes

        # don't touch below this line

    def exists(self, val):
        if val == self.val:
            return True

        if val < self.val:
            if self.left is None:
                return False
            return self.left.exists(val)

        if self.right is None:
            return False
        return self.right.exists(val)

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